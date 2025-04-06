#ifndef QUESTION_H
#define QUESTION_H

#include <string>

// Define the types of questions.
enum QuestionType {
    MCQ,  // Multiple Choice Question
    TF,   // True/False Question
    WR    // Written Response Question
};

// Structure for an answer choice (for MCQs).
struct Choice {
    char letter;             // e.g., 'A', 'B', etc.
    std::string text;        // The text for the answer choice.
    Choice* next;            // Pointer to the next choice.
};

// Structure for a quiz question node.
struct Question {
    int id;                  // Unique identifier (set later).
    QuestionType type;       // The type of question.
    std::string questionText;// The question text.
    double pointValue;       // Point value for the question.
    std::string correctAnswer; // For MCQ, the correct letter (or answer text for TF/WR).
    std::string studentAnswer; // To store the student's answer.
    Choice* choices;         // For MCQs: pointer to the first choice (nullptr for others).
    Question* next;          // Pointer to the next question in the list.
};

// Function prototypes for linked list operations:

// Creates a new question node.
Question* createQuestion(QuestionType type, const std::string &text, double pointValue, const std::string &correctAnswer);

// Appends a new question node to the end of the linked list.
void appendQuestion(Question*& head, Question* newQuestion);

// For MCQs: Adds a new answer choice to a question.
void addChoice(Question* q, char letter, const std::string &choiceText);

// Displays the entire question bank (for debugging).
void printQuestionBank(Question* head);

// Frees all memory used by the question bank.
void deleteQuestionBank(Question* head);

#endif // QUESTION_H

