import numpy as np
import scipy.signal
import scipy.io.wavfile

# Indlæs lydfilerne
sample_rate_A, recordingA = scipy.io.wavfile.read('original.wav')
sample_rate_B, recordingB = scipy.io.wavfile.read('cover.wav')

# Definer længden af segmenterne
segmentLength = 1024

# Beregn antallet af segmenter (for det korteste signal)
numSegments = min(len(recordingA), len(recordingB)) // segmentLength

# Initialiser samlet score for krydskorrelation
totalScoreXcorr = 0

for i in range(numSegments):
    segmentA = recordingA[i * segmentLength:(i + 1) * segmentLength]
    segmentB = recordingB[i * segmentLength:(i + 1) * segmentLength]

    corr = scipy.signal.correlate(segmentA, segmentB, mode='full', method='auto')
    maxCorr = np.max(np.abs(corr)) / segmentLength
    score = maxCorr * 100
    totalScoreXcorr += score

# Gennemsnitlig score for alle segmenter
finalScoreXcorr = totalScoreXcorr / numSegments
print ('finalScoreXcorr: ' + str(finalScoreXcorr))

# Sørg for, at både recordingA og recordingB er vektorer
recordingA = recordingA.flatten()
recordingB = recordingB.flatten()

# Beregn energien i hvert signal
energyA = np.sum(recordingA ** 2)
energyB = np.sum(recordingB ** 2)

# Beregn en score baseret på, hvor godt recordingB matcher energien i recordingA
finalScoreEnergy = (min(energyA, energyB) / max(energyA, energyB)) * 100
print ('finalScoreEnergy: ' + str(finalScoreEnergy))

# Samlet endelig score (gennemsnit af de to scores)
finalScore = (finalScoreEnergy + finalScoreXcorr) / 2

print('Den samlede score er:', finalScore)