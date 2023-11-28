#

import numpy as np
import scipy.io.wavfile as wav

# Load audio files
file1 = "Justin_Bieber_-_Ghost.wav"


# Read audio data
rate1, data1 = wav.read(file1)
print("Rate:", rate1)
# Convert audio data to mono if necessary
if len(data1.shape) > 1:
    data1 = data1[:, 0]



print("Data:", data1)



# Calculate correlation coefficient
#corr_coef = np.corrcoef(data1, data2)[0, 1]

# Print the correlation coefficient
#print("Correlation Coefficient:", corr_coef)

