#correlation.py
#Max Glintborg Dall & Oliver Kok
import scipy.io.wavfile as wav
import scipy.signal as signal
from ControlUnit import ControlUnit 

# For plotting, used in tests. Remove after tests
import matplotlib.pyplot as plt

import ControlUnit
from scipy.signal import stft
from pydub import AudioSegment
from pydub.playback import play
from scipy.io import wavfile
import numpy as np

# This logicUnit class is so badly made its sad. There should not be a need to create controlUnit in this class,
# but we have, and this should be changed.
class LogicUnit:
    def __init__(self):
        # Create an instance of ControlUnit
        self.controlUnit = ControlUnit()

        # Access and store the get functions
        self.chosenSongVocals = self.controlUnit.get_chosenSongVocals()
        self.recordedSongVocals = self.controlUnit.get_recordedSong()

    # Load audiofile, for STFT TESTING ONLY! REMOVE AFTER TESTS
    def readAudioFile(self, audio_file):
        # load audio files
        sampleRate, dataArray = wav.read(audio_file)

        print(f"number of channels = {dataArray.shape[1]}")
        length = dataArray.shape[0] / sampleRate
        print(f"length = {length}s")
        length = 0.01

    # Plot for testing only! remove after tests
        time = np.linspace(0., length, dataArray.shape[0])
        plt.plot(time, dataArray[:, 0], label="Left channel")
        plt.plot(time, dataArray[:, 1], label="Right channel")
        plt.legend()
        plt.xlabel("Time [s]")
        plt.ylabel("Amplitude")
        plt.show()

    # Return the audiofile, sampleRate and length
        return dataArray, sampleRate, length

    # Audio segmentation
    def audio_segmentation(self,audio_file):
        # load audio files
        sampleRate, dataArray = wav.read(audio_file)

        # Number of segments
        num_segments = 20

        segment_length = len(dataArray) // num_segments
        segments = np.zeros((num_segments, segment_length))
    
    # For loop, that goes through the audiofile and segments it into 20 segments.
        for i in range(num_segments):  
            start_idx = i * segment_length
            end_idx = (i + 1) * segment_length
            current_segment = dataArray[start_idx:end_idx]
            segments[i, :] = current_segment    # 2D array in the form of (num_segments, segment_length)
            
        return segments
    
    # Correlate the recorded song with the chosen song, using the audio_segmentation function
    def correlate(recordedSegment, chosenSegment):
        corr = signal.correlate(recordedSegment, chosenSegment, mode='full', method='auto')
        print ("Cross-correlation result:", corr)   # Print the result of the correlation
        return corr
       