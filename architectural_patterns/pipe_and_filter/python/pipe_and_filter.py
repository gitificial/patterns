import string

# ---------- Filters ----------

def remove_punctuation(text):
    return text.translate(str.maketrans('', '', string.punctuation))

def to_lowercase(text):
    return text.lower()

def split_words(text):
    return text.split()

def remove_stopwords(words):
    stopwords = {"the", "and", "is", "in", "to", "of"}
    return [word for word in words if word not in stopwords]

# ---------- Pipe Runner ----------

def run_pipeline(data, filters):
    for f in filters:
        data = f(data)
    return data

# ---------- Main Program ----------

if __name__ == "__main__":
    text = "The quick brown fox jumps over the lazy dog, in the garden of Eden."

    pipeline = [
        remove_punctuation,
        to_lowercase,
        split_words,
        remove_stopwords
    ]

    result = run_pipeline(text, pipeline)
    print("Filtered words:", result)
