from controlUnit import ControlUnit

# Testing in main script
if __name__ == "__main__":
    control_unit = ControlUnit()
    song_file_name = 'Justin_Bieber_-_Ghost.wav'  # Replace with the actual name of your song file
    control_unit.play_song(song_file_name)
