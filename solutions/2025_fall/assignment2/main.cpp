/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <cstddef>
#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

std::string kYourName = "Francisco Mendes"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream file {filename};
  if (!file.is_open()) {
    std::cerr << "Error opening file: " << filename << std::endl;
    exit(-1);
  }

  std::set<std::string> applicants;
  std::string line;
  while(std::getline(file, line)) {
    applicants.insert(line);
  }

  return applicants;
}

std::pair<char, char> get_initials(std::string name) {
  // Convert name to stream for easy parsing
  std::istringstream name_stream{name};

  char first, last;
  std::string line;
  std::getline(name_stream, line, ' ');
  first = line[0];
  std::getline(name_stream, line, ' ');
  last = line[0];
  return {first, last};
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // Store name innitials
  std::pair<char, char> initials{get_initials(name)};

  std::queue<const std::string*> matches;
  for (const auto& student : students) {
    if (initials == get_initials(student)) {
      matches.push(&student);
    }
  }

  return matches;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  const std::string * result;
  if (matches.size() == 0) {
    std::cout << "NO MATCHES FOUND." << std::endl;
    return *result;
  }

  // Generate random number in the range of the queue size
  size_t random_index = rand() % matches.size();

  for (size_t i = 0; i < random_index; ++i) {
    matches.pop();
  }
  result = matches.back();

  return *result;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
