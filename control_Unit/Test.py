import numpy as np
from scipy.io import wavfile
from scipy.signal import stft, correlate
import matplotlib.pyplot as plt

# Load two audio files
chosenSong = 'justin_bieber_ghost[vocals].wav'
recording = 'cover_justin_bieber_ghost[vocals].wav'
sample_rate_1, data_1 = wavfile.read(chosenSong)
sample_rate_2, data_2 = wavfile.read(recording)

# Use only one channel if the audio is stereo
if len(data_1.shape) > 1:
    data_1 = data_1[:, 0]
if len(data_2.shape) > 1:
    data_2 = data_2[:, 0]

def Pearson_correlation(Chosensong,Recording):
    if len(Chosensong)==len(Recording):
        score = sum((chosenSong-chosenSong.mean())*(recording-recording.mean()))
        Sum_chosen_squared = sum((Chosensong-Chosensong.mean())**2)
        Sum_recorded_squared = sum((Recording-Recording.mean())**2)       
        corr = score / np.sqrt(Sum_chosen_squared * Sum_recorded_squared)
    return corr
             
print(Pearson_correlation(chosenSong,recording))
print(Pearson_correlation(chosenSong,chosenSong))