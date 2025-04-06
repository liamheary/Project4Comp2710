#ifndef QUIZ_OPERATIONS_H
#define QUIZ_OPERATIONS_H

#include "question.h"  // Make sure you have this header too.
#include <string>
using std::string;

// Enum to represent question types (adjust as needed)
enum QuestionType { MCQ, TF, WR };

// Define your QuestionNode structure. This is just an example structure:
struct QuestionNode {
    QuestionType type;
    string questionText;
    string correctAnswer;
    double pointValue;
    // For MCQ, you might store choices in a linked list as well (without arrays!)
    // For example, you could have a pointer to a ChoiceNode structure:
    // ChoiceNode* choices;
    // Pointer to the next question node:
    QuestionNode* next;
};

// Function prototypes:

// Creates a new question node.
QuestionNode* createQuestionNode(QuestionType type, const string &questionText, const string &correctAnswer, double pointValue);

// Appends a new node to the end of the linked list.
void appendQuestion(QuestionNode*& head, QuestionNode* newQuestion);

void addMCQChoice(QuestionNode* question, char letter, const string &choiceText);

void displayQuestion(const QuestionNode* question);

void editQuestion(QuestionNode* question);
QuestionNode* deleteQuestion(QuestionNode* head, int questionNumber);

#endif // QUIZ_OPERATIONS_H

