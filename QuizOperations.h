#ifndef QUIZ_OPERATIONS_H
#define QUIZ_OPERATIONS_H

#include "question.h"

// Function prototypes for linked list operations:
QuestionNode* createQuestionNode(QuestionType type, const string &questionText, const string &correctAnswer, double pointValue);
void appendQuestion(QuestionNode*& head, QuestionNode* newQuestion);
void addMCQChoice(QuestionNode* question, char letter, const string &choiceText);
void displayQuestion(const QuestionNode* question);

// Stub functions for editing/deleting (to be expanded in Phase 2)
void editQuestion(QuestionNode* question);
QuestionNode* deleteQuestion(QuestionNode* head, int questionNumber);

#endif // QUIZ_OPERATIONS_H

