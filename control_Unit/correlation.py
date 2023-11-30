#controlUnit
#Max Glintborg Dall & Oliver Kok

import numpy as np
import scipy.io.wavfile as wav
from scipy.signal import stft
from pydub import AudioSegment
from pydub.playback import play
from scipy.io import wavfile

def stft_segmentation(audio_file, num_segments=20):
    try:
        # Read the stereo audio file
        sample_rate, stereo_samples = wavfile.read(audio_file)

        # Ensure stereo_samples is a 2D array
        if len(stereo_samples.shape) == 1:
            stereo_samples = stereo_samples[:, np.newaxis]

        # Calculate window size for STFT
        window_size = stereo_samples.shape[0] // num_segments

        # Perform STFT on each channel separately
        stft_results_left = stft(stereo_samples[:, 0], fs=sample_rate, nperseg=window_size, noverlap=window_size//2)[2]
        stft_results_right = stft(stereo_samples[:, 1], fs=sample_rate, nperseg=window_size, noverlap=window_size//2)[2]

        return stft_results_left, stft_results_right

    except Exception as e:
        print(f"Error performing STFT: {e}")
        return None, None

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
