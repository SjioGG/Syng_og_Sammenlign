import sqlite3

# Snake case default, NO CAPS for table names or contents

# Connect to SQLite database (creates a new database if it doesn't exist)
conn = sqlite3.connect('sos.db')
cursor = conn.cursor()

# Create 'users' table
cursor.execute('''
    CREATE TABLE IF NOT EXISTS artist (
        id INTEGER PRIMARY KEY,
        name TEXT NOT NULL
    )
''')

# Create 'posts' table with a foreign key referencing 'users' table
cursor.execute('''
    CREATE TABLE IF NOT EXISTS song (
        id INTEGER PRIMARY KEY,
        artist_id INTEGER NOT NULL,
        title TEXT NOT NULL,
        duration INTEGER NOT NULL,
        key TEXT NOT NULL,
        instrumental_file TEXT NOT NULL,
        cmp_melody_file TEXT NOT NULL,
        lyrics_file TEXT NOT NULL,
        FOREIGN KEY (artist_id) REFERENCES artist (id)
    )
''')

cursor.execute('''
    CREATE TABLE IF NOT EXISTS score (
        id INTEGER PRIMARY KEY,
        song_id INTEGER NOT NULL,
        score_value INT NOT NULL,
        user TEXT NOT NULL,
        date TEXT NOT NULL,
        FOREIGN KEY (song_id) REFERENCES song (id)
    )
''')

# SAMPLE DATE:
# Insert sample data into 'artist' table
cursor.execute("INSERT INTO artist (name) VALUES ('John Doe')")
cursor.execute("INSERT INTO artist (name) VALUES ('Jane Smith')")

# Insert sample data into 'song' table
cursor.execute("INSERT INTO song (artist_id, title, duration, key, instrumental_file, cmp_melody_file, lyrics_file) VALUES (1, 'Sample Song 1', 240, 'C', 'instrumental1.mp3', 'melody1.mp3', 'lyrics1.txt')")
cursor.execute("INSERT INTO song (artist_id, title, duration, key, instrumental_file, cmp_melody_file, lyrics_file) VALUES (2, 'Sample Song 2', 180, 'G', 'instrumental2.mp3', 'melody2.mp3', 'lyrics2.txt')")

# Insert sample data into 'score' table
cursor.execute("INSERT INTO score (song_id, score_value, user, date) VALUES (1, 90, 'user1', '2023-01-01')")
cursor.execute("INSERT INTO score (song_id, score_value, user, date) VALUES (2, 85, 'user2', '2023-01-02')")


# Commit the changes and close the connection
conn.commit()
conn.close()

print("Database created successfully with tables 'users' and 'posts'.")
