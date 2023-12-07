import numpy as np
from scipy.io import wavfile
from scipy.signal import stft, correlate
import matplotlib.pyplot as plt

# Load two audio files
file_path_1 = 'justin_bieber_ghost[vocals].wav'
file_path_2 = 'cover_justin_bieber_ghost[vocals].wav'
sample_rate_1, data_1 = wavfile.read(file_path_1)
sample_rate_2, data_2 = wavfile.read(file_path_2)

# Use only one channel if the audio is stereo
if len(data_1.shape) > 1:
    data_1 = data_1[:, 0]
if len(data_2.shape) > 1:
    data_2 = data_2[:, 0]

# Set the number of segments to 20
num_segments = 20

# Calculate the segment size and overlap for each audio file
segment_size_1 = len(data_1) // num_segments
overlap_1 = segment_size_1 // 2

segment_size_2 = len(data_2) // num_segments
overlap_2 = segment_size_2 // 2

# Initialize an array to store cross-correlation values for each segment
cross_corr_segments = []

# Iterate over each segment and calculate cross-correlation
for i in range(num_segments):
    # Define the start and end indices for the current segment
    start_idx = i * segment_size_1
    end_idx = start_idx + segment_size_1
    
    # Extract the current segment from each audio file
    segment_1 = data_1[start_idx:end_idx]
    segment_2 = data_2[start_idx:end_idx]

    # Compute STFT for both segments
    _, _, Zxx_1 = stft(segment_1, fs=sample_rate_1, nperseg=segment_size_1, noverlap=overlap_1)
    _, _, Zxx_2 = stft(segment_2, fs=sample_rate_2, nperseg=segment_size_2, noverlap=overlap_2)

    # Perform cross-correlation for the current segment
    cross_corr_segment = correlate(Zxx_1, Zxx_2)
    
    # Append the result to the array
    cross_corr_segments.append(cross_corr_segment)

# Convert the list of cross-correlation segments to a NumPy array
cross_corr_segments = np.array(cross_corr_segments)

# Plotting example: plot the cross-correlation for each segment
for i in range(num_segments):
    plt.plot(cross_corr_segments[i], label=f'Segment {i+1}')

plt.xlabel('Time Lag')
plt.ylabel('Cross-Correlation')
plt.legend()
plt.show()