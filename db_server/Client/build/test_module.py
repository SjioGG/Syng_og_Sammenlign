import py_dbserver

# Now you can use py_dbserver as usual

def test_song():
    # SONG CLASS TEST
    song = py_dbserver.Song(1)
    song_string = song.get_data(1)
    print("OG STRING:    ", song_string)
    song.parse_string(song_string)
    print("ARTIST:       ", song.get_artist())
    print("TITLE:        ", song.get_title())
    print("LENGTH:       ", song.get_duration())
    print("KEY:          ", song.get_key())
    print("INSTRUMENTAL: ", song.get_instrumental_file())
    print("MELODY:       ", song.get_cmp_melody_file())
    print("LYRICS:       ", song.get_lyrics_file())

def test_score_list():
    # SCORE CLASS TEST
    score_list = py_dbserver.ScoreList()
    score_string = score_list.get_data(1)

    print("OG STRING:    ", score_string)
    print("ScoreList:")
    
    top10 = score_list.get_scores()
    print(top10[1].get_score_value())

    methods = ['get_id', 'get_song_id', 'get_score_value', 'get_user', 'get_date']

    for score in top10:
        for method in methods:
            result = getattr(score, method)()
            print(f"{method}: {result}")


def test_add_score():
    # TEST ADD FUNCTION
    score = py_dbserver.Score()
    score.add_score(1, 9000, "Boobman69", "2011-11-11")

if __name__ == "__main__":
    test_song()
    test_score_list()
    test_add_score()
