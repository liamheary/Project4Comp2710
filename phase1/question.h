#ifndef QUESTION_H
#define QUESTION_H

#include <string>
using std::string;

// Enum for question types.
enum QuestionType { MCQ, TF, WR };

// Node for multiple choice answer options.
struct ChoiceNode {
    char letter;           // e.g., 'A', 'B', etc.
    string choiceText;     // Text for the choice.
    ChoiceNode* next;      // Pointer to next choice.
};

// Node for each question.
struct QuestionNode {
    int id;                // An optional ID (for editing/deleting).
    QuestionType type;     // MCQ, TF, or WR.
    string questionText;   // The text of the question.
    string correctAnswer;  // The correct answer (for MCQ: the letter; TF: "true"/"false"; WR: the answer text).
    double pointValue;     // Must be non-negative.
    string studentAnswer;  // To store the student's answer during assessment.
    ChoiceNode* choices;   // For MCQs: pointer to linked list of choices (NULL for TF/WR).
    QuestionNode* next;    // Pointer to next question.
};

#endif // QUESTION_H

