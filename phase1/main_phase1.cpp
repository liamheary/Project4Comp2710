#include <iostream>
#include "question.h"
#include "QuizOperations.h"

using namespace std;

int main() {
    // Initialize question bank (empty list)
    QuestionNode* bank = nullptr;

    // Create an MCQ question.
    QuestionNode* q1 = createQuestionNode(MCQ, "Which approach is used by C++?", 10.00, "C");
    addChoice(q1, 'A', "Left-right");
    addChoice(q1, 'B', "Right-left");
    addChoice(q1, 'C', "Bottom-up");
    addChoice(q1, 'D', "Top-down");
    appendQuestion(bank, q1);

    // Create a True/False question.
    QuestionNode* q2 = createQuestionNode(TF, "In a flowchart, the switch diamond requires a true/false answer.", 12.50, "false");
    appendQuestion(bank, q2);

    // Create a Written Response question.
    QuestionNode* q3 = createQuestionNode(WR, "By default, all the files in C++ are opened in what mode?", 17.50, "text");
    appendQuestion(bank, q3);

    // Print the created question bank.
    cout << "=== Question Bank ===" << endl;
    printQuestionBank(bank);

    // Edit the first question.
    editQuestion(bank, 1, "Which approach is primarily used by C++?", 10.00);

    // Delete the second question.
    deleteQuestion(bank, 2);

    cout << "\n=== Updated Question Bank ===" << endl;
    printQuestionBank(bank);

    // Clean up all allocated memory.
    deleteQuestionBank(bank);
    return 0;
}

