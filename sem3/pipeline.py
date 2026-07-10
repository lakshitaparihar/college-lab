from transformers import pipeline

classifier=pipeline('sentiment-analysis')
classifier("i wish i had a sea facing villa of my own.")
classifier("i think the performance was'nt very satisfying.")