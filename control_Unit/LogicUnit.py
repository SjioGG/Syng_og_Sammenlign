#correlation.py
#Max Glintborg Dall & Oliver Kok

import numpy as np
import scipy.io.wavfile as wav
import scipy.signal as signal

from scipy.signal import stft
from pydub import AudioSegment
from pydub.playback import play
from scipy.io import wavfile

controllUnit = controllUnit()
controllUnit.get_chosenSongVocals() = chosenSongVocals
controllUnit.get_recordedSong() = recordedSongVocals

# Class for correlation, used to initialize the chosen song and the recorded song, and to calculate the correlation between them.
class _LogicUnit_:
    def __init__(self, chosenSongVocals, recordedSongVocals):
        self.chosenSongVocals = chosenSongVocals
        self.recordedSongVocals = recordedSongVocals

# STFT Logic
# This function is used to take an audiofile, in the .wav format, and split it into segments.
# These segments correlate to 5% each, splitting it into 20 segments. This is done to both the left and right channel.
# The function returns the STFT of the left and right channel, which is used to then calculate correlation in the correlation Logic.
def stft_segmentation(audio_file, num_segments=20):
    try:
        # Read the stereo audio file
        sample_rate, stereo_samples = wavfile.read(audio_file)
 
        # Ensure stereo_samples is a 2D array
        if len(stereo_samples.shape) == 1:
            stereo_samples = stereo_samples[:, np.newaxis]
        else:
            print ("Converting to 2D array FAILED")

        # Calculate window size for STFT
        window_size = stereo_samples.shape[0] // num_segments

        # Perform STFT on each channel separately
        stft_results_left = stft(stereo_samples[:, 0], fs=sample_rate, nperseg=window_size, v=window_size//2)[2]
        stft_results_right = stft(stereo_samples[:, 1], fs=sample_rate, nperseg=window_size, noverlap=window_size//2)[2]

        return stft_results_left, stft_results_right

    except Exception as e:
        print(f"Error performing STFT: {e}")
        return None, None
    
# Sudo sudo code.
def corelation(chosenSongVocals, recordedSongVocals):
    result = scipy.signal.correlate(stft_segmentation(chosenSongVocals), stft_segmentation(recordedSongVocals), method='direct') # Returns correlation between the two songs
    return result
    print(result)
    


# Correlation Logic
def normalized_cross_correlation(stft_results1, stft_results2):
    flat_results1 = stft_results1.reshape(stft_results1.shape[0], -1)
    flat_results2 = stft_results2.reshape(stft_results2.shape[0], -1)

    cross_corr = np.correlate(flat_results1, flat_results2, mode='full')
    norm_cross_corr = cross_corr / (np.linalg.norm(flat_results1) * np.linalg.norm(flat_results2))

    return norm_cross_corr

def similarity_score(norm_cross_corr):
    scaled_score = 5 * (norm_cross_corr + 1)
    scaled_score = np.clip(scaled_score, 0, 10)
    return scaled_score

# Example usage
file1 = "Justin_Bieber_-_Ghost.wav"
file2 = "Recording.wav"

stft_results1_left, stft_results1_right = stft_segmentation(file1)
stft_results2_left, stft_results2_right = stft_segmentation(file2)

# Use either left or right channels, or combine them based on your requirements
norm_cross_corr_left = normalized_cross_correlation(stft_results1_left, stft_results2_left)
norm_cross_corr_right = normalized_cross_correlation(stft_results1_right, stft_results2_right)

# Average the similarity scores from left and right channels
final_similarity_score = 0.5 * (similarity_score(norm_cross_corr_left) + similarity_score(norm_cross_corr_right))

print(f"Similarity Score: {final_similarity_score}")
