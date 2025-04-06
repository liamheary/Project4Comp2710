#ifndef QUESTION_H
#define QUESTION_H

#include <string>

// Enumeration for question types.
enum QuestionType { MCQ, TF, WR };

// Node for an MCQ choice.
struct ChoiceNode {
    char letter;
    std::string choiceText;
    ChoiceNode* next;
};

// Node for a question.
struct QuestionNode {
    QuestionType type;
    std::string questionText;
    double pointValue;
    std::string correctAnswer;
    std::string studentAnswer;  // To record the test taker’s answer.
    ChoiceNode* choices;        // Only used for MCQ.
    QuestionNode* next;
};

// Function prototypes for linked list operations.
QuestionNode* createQuestionNode(QuestionType type, const std::string &questionText, double pointValue, const std::string &correctAnswer);
void appendQuestion(QuestionNode*& head, QuestionNode* newQuestion);
void addChoice(QuestionNode* q, char letter, const std::string &choiceText);
void printQuestionBank(const QuestionNode* head);
void deleteQuestionBank(QuestionNode*& head);

// Functions for editing/deleting a specific question.
void editQuestion(QuestionNode* head, int questionNumber, const std::string &newText, double newPointValue);
void deleteQuestion(QuestionNode*& head, int questionNumber);

#endif // QUESTION_H

