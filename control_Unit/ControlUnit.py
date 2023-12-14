
import numpy as np
import scipy.io.wavfile as wav
from playsound import playsound
from pydub.playback import play

class ControlUnit():
    def __init__(self):
        # Initialize any necessary variables or parameters here
        self.chosenSongVocals = None
        self.recordedSongVocals = None

 # Get functions for the recorded song (PSoC) and the chosen song (DB/Server)
    def get_chosenSongMelody(self):
        chosenSongMelody = "justin_bieber_ghost[music].wav"  # Replace with actual logic
        return chosenSongMelody
    
    def get_chosenSongVocals(self):
        self.chosenSongVocals = "justin_bieber_ghost[vocals].wav"
        return self.chosenSongVocals

    def get_recordedSong(self):
        self.recordedSongVocals = "cover_justin_bieber_ghost[vocals].wav"
        return self.recordedSongVocals
    
    def get_finalScore(self):
        finalScore = "100"  # Replace with actual logic

# Play function, to play any song. 
    def play_song(self, song_file):
        print(f"Playing song: {song_file}")
        playsound(song_file)
        print("Song playback complete")