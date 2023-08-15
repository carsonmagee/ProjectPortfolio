# Music Database
This project was created using Structured Query Language within the SQLite Online Database Software. The main purpose of this project is to present the basic uses and key concepts of SQL through a music database. 

## Motivation
The motivation behind this project was to explore software other than MySQL, which I am more familiar with. I found the online browser version of SQLite quite convenient, the only issues I had were sourced from the database I used. 

## Features
10 queries are listed to make competent analysis of the chosen music database.

## Reflection
I found difficulty within the chosen database. It appeared, after downloading the database, that it was meant 
to hold multiple tables within the download, however, I could not find a way to parse the download into multiple tables.

## Installation
Download the music.db database from [CORGIS Project Site](https://corgis-edu.github.io/corgis/csv/music/)  
Open [SQLite Online](https://sqliteonline.com/)
Click File >Open DB <img src="https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/9d61ee3a-7b51-4f6e-8df4-bb0e97b82707" width="200" />
Select the music.DB file from your downloads <img src="https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/439ff957-3dfd-492d-87e1-d35da9f22452" width="200" />
Copy and past the queries (found below in the tests section) into the text box within SQLite Online. All tests and their screenshots can be found below.


## Personal Requirements
### Demonstrates most rudementary queries
•	Answers 10 different questions about the data 
•	Questions must be specific to the data 
•	Answers are supported by screenshot 
•	Queries must select only the relevant columns  
•	No SELECT * statements 
•	Use MIN or MAX in at least two different queries 
•	Use WHERE in at least five different  queries 
•	Use AND or OR in at least one query 
•	Use COUNT in at least one query 
•	Use AVG or SUM in at least two different queries 
•	Use LIKE to filter data in at least three different queries 

## Tests
Question 1
1.	What artists have the letters ‘y’ and ‘j’ and ‘x’ in their name? (Presents the use of the LIKE and WHERE and AND statements)
2.	DJ X-Change featuring DJ Joey A, Xzibit featuring Jayo Felony and Method Man, Maurice Chevalier …, Wyclef Jean….
3.	SELECT "artist.name" 
FROM music
WHERE "artist.name" LIKE('%y%') AND "artist.name" LIKE('%j%') AND "artist.name" LIKE('%x%');
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/101ea552-7eb6-407d-887a-367b0f182499)


Question 2
1.	Which artists is hottest? What is their rating? (Presents the use of the MAX statement)
2.	Lextrical, 0,.0
3.	SELECT "artist.name" , min("artist.hotttnesss")
FROM music;
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/9aa00784-39eb-4cdc-8530-3ba4bd9bdbb3)


Question 3
1.	Which artist is least hot? What is their rating? (Presents the use of the MIN statement)
2.	Kanye West, 1.08250
3.	SELECT "artist.name" , max("artist.hotttnesss")
FROM music;
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/c98b81df-d7ad-4ef0-a5d5-8f246584a366)


Question 4
1.	How many songs are in the key of G (5.0)? (Presents the use of the COUNT and LIKE and WHERE statements)
2.	795 songs in G
3.	SELECT "song.key", COUNT("song.key") AS "Songs in G"
FROM music
WHERE "song.key" LIKE('%5.0%');
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/b6542744-df1d-43bf-be71-e92abd2f8911)


Question 5
1.	What is the average song tempo? (Presents the use of the AVG statement)
2.	122.900913210
3.	SELECT AVG("song.tempo") AS "Average Song Tempo"
FROM music;
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/410dacf3-1cac-45d9-98bb-8a25cff8042d)


Question 6
1.	How long is every song combined in minutes? (Presents the use of the SUM statement)
2.	40103.67 minutes
3.	SELECT "song.name", SUM("song.duration")/60 AS "Total length"
FROM music;
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/44371a97-0a12-40ca-b86b-460f5c15a22a)


Question 7
1.	What song has -25.924 db loudness? (Use song id -- song name does not work in this database) (Presents the use of LIKE and WHERE statements)
2.	Song ID: SOFCDUZ12AB01861C6
3.	SELECT "song.id", "song.loudness"
FROM music
WHERE "song.loudness" LIKE "%-25.924%";
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/25c7c7cd-6b8f-464c-90b6-3e6251e60390)


Question 8
1.	What songs are by Casual? (Presents the use of the LIKE and WHERE statements)
2.	"Casual"	"SOMZWCG12A8C13C480"
"Casual"	"SOQLGFP12A58A7800E"
"Casual"	"SODKPKO12A58A79DF7"
"Casual"	"SOZWTCR12A58A7BA31"
"Casual"	"SOXPJJT12AB01843F5"
"Casual"	"SOCTKZS12A58A7C5E6"
"Casual"	"SOAPMKZ12A58A764B7"
"Casual"	"SOIYNOF12AB0182141"
3.	SELECT "artist.name", "song.id"
FROM music
WHERE "artist.name" LIKE "%casual%";
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/2561e191-5137-477e-8f05-d376f27c2599)


Question 9
1.	Which song has a tempo with “60” in it? (Presents the use of the LIKE and WHERE statements)
2.	89.607
3.	SELECT "song.id", "song.tempo"
FROM music
WHERE "song.tempo" LIKE "%60%";
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/8afca82c-b80c-41f7-aa99-9f3df23415eb)


Question 10
1.	What song has a song.id and an artist.id with ‘WX’? (Presents the use of the LIKE and WHERE statements)
2.	Song ID: SOMXWXQ12AC3DFA002	 
Artist ID: ARWXHRS1241B9C7A1E
3.	SELECT "song.id", "artist.id"
FROM music
WHERE "song.id" LIKE "%WX%" AND "artist.id" LIKE "%WX%";
4.	 ![image](https://github.com/carsonmagee/ProjectPortfolio/assets/24598567/67a8c62b-8aed-4a74-b60d-4c3a6b0ee3c3)






