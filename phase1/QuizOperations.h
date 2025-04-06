#ifndef QUIZOPERATIONS_H
#define QUIZOPERATIONS_H

#include "question.h"

void editQuestion(QuestionNode* head, int questionNumber, const std::string &newText, double newPointValue);
void deleteQuestion(QuestionNode*& head, int questionNumber);

#endif // QUIZOPERATIONS_H

