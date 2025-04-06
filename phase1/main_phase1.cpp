#include "question.h"
#include <iostream>
using namespace std;

int main() {
    // Create an empty question bank.
    Question* bank = nullptr;

    // Create an MCQ question.
    Question* q1 = createQuestion(MCQ, "Which of the following approach is used by C++?", 10.00, "C");
    // Add answer choices for the MCQ.
    addChoice(q1, 'A', "Left-right");
    addChoice(q1, 'B', "Right-left");
    addChoice(q1, 'C', "Bottom-up");
    addChoice(q1, 'D', "Top-down");
    q1->id = 1;
    appendQuestion(bank, q1);

    // Create a True/False question.
    Question* q2 = createQuestion(TF, "In a flowchart, the switch diamond requires a true/false answer.", 12.50, "false");
    q2->id = 2;
    appendQuestion(bank, q2);

    // Create a Written Response question.
    Question* q3 = createQuestion(WR, "By default, all the files in C++ are opened in what mode?", 17.50, "text");
    q3->id = 3;
    appendQuestion(bank, q3);

    // Display the question bank.
    cout << "=== Question Bank ===\n";
    printQuestionBank(bank);

    // Free memory.
    deleteQuestionBank(bank);
    return 0;
}

