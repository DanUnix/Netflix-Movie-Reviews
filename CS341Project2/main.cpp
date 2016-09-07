//
// Netflix Movie Review Analysis
//
// <<Daniel Pulley>>
// U. of Illinois, Chicago
// CS341, Fall 2016
// HW #02
//

// Preprocess Directives
#include <iostream>
#include <iterator>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Movie.h"
#include "Review.h"

// using namespace std
using std::string;
using std::ifstream;
using std::vector;
using std::stringstream;
using std::getline;
using std::stoi;
using std::sort;
using std::cout;
using std::endl;
using std::setw;
/*
 * inputMovies function
 * 
 * Function takes movie vector and then inputs data from movies CSV file into the vector
 */
void inputMovies(vector<Movie>& myMovie)
{
	// Open movie.csv file
	ifstream movie_file("movies.csv");


	// String values to get Movie statistics
	string line, movie_id, movie_name, publish_year;

	// Check if movies file exist, if not exit program
	if (!movie_file.good()) {
		cout << "Cannot open movie file!" << endl;
		cout << "Exiting Program!" << endl;
		return;
	}

	// Skip header
	getline(movie_file, line);

	while (getline(movie_file, line)) {

		// Use stringstream to help parse CSV file
		stringstream ss(line);

		// parse line:
		getline(ss, movie_id, ',');
		getline(ss, movie_name, ',');
		getline(ss, publish_year);

		Movie M(stoi(movie_id), movie_name, stoi(publish_year));

		// insert @ end
		myMovie.push_back(M);
	}
}
/* End of inputMovies File */

/*
* inputReviews function
*
* Function takes review vector and then inputs data from reviews CSV file into the vector
*/
void inputReviews(vector<Review>& myReview)
{
	// Open Review CSV file
	ifstream review_file("reviews.csv");


	// String values to get Movie statistics
	string line, movie_id, user_id, movie_rating, review_date;

	// Check if movies file exist, if not exit program
	if (!review_file.good()) {
		cout << "Cannot open review file!" << endl;
		cout << "Exiting Program!" << endl;
		return;
	}

	// Skip header
	getline(review_file, line);

	while (getline(review_file, line)) {

		// Use stringstream to help parse CSV file
		stringstream ss(line);

		// parse line:
		getline(ss, movie_id, ',');
		getline(ss, user_id, ',');
		getline(ss, movie_rating, ',');
		getline(ss, review_date);

		Review R(stoi(movie_id), stoi(user_id), stoi(movie_rating), review_date);

		// insert @ end
		myReview.push_back(R);
	}
}
/* End of inputReviews Function */

/*
 * topTenMovies Function
 * Function displays the top-10 movies (based on average rating)
 *
 */
void topTenMovies(vector<Movie>& myMovie, vector<Review>& myReview)
{
	cout << endl << ">> Top-10 Movies <<" << endl << endl;
	
	// Display top ten movies
	cout << "Rank" << setw(10) << "ID" << setw(10) << "Reviews" << setw(10) << "Avg" << setw(10) << "Name" << endl;
	for (auto i = 1; i <= 10; ++i) {
	
		cout << i << "." << endl;
	}
}	
/* End of topTenMovies */

/* 
 * main Function
 *
 */
int main()
{
	// Print Title of Program
	cout << "** Netflix Movie Review Analysis **" << endl;
	
	// Create Movie vector to input movie data from file
	vector<Movie> movies;
	// Input movies into vector
	inputMovies(movies);
	// Create Review vector to input review data from file
	vector<Review> reviews;
	// Input reviews into vector
	inputReviews(reviews);
	
	// Display number of movies and number of reviews
	cout << ">> Reading movies... " << movies.size() << endl;
	cout << ">> Reading reviews... " <<  reviews.size() << endl;

	// Display top 10 movies
	topTenMovies(movies,reviews);

	cout << "** DONE! ** " << endl;
	system("PAUSE");
}
/* End of Main Function */