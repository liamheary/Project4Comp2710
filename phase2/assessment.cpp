#include "assessment.h"
#include <iostream>
#include <cctype>
#include <algorithm>
using std::cout;
using std::cin;
using std::endl;
using std::string;

// Helper function: compares two strings case-insensitively.
bool caseInsensitiveCompare(const string &a, const string &b) {
    string aa = a, bb = b;
    std::transform(aa.begin(), aa.end(), aa.begin(), ::tolower);
    std::transform(bb.begin(), bb.end(), bb.begin(), ::tolower);
    return aa == bb;
}

// This function goes through the linked list and performs the assessment.
void runAssessment(QuestionNode* head) {
    if (!head) {
        cout << "No questions available for assessment.\n";
        return;
    }
    double totalPoints = 0.0, earnedPoints = 0.0;
    int count = 0;
    // First, calculate total points and count questions.
    for (QuestionNode* curr = head; curr != nullptr; curr = curr->next) {
        totalPoints += curr->pointValue;
        count++;
    }
    cout << "Total questions: " << count << "\nTotal points available: " << totalPoints << "\n";
    
    int qNum = 1;
    for (QuestionNode* curr = head; curr != nullptr; curr = curr->next, qNum++) {
        cout << "\nQuestion " << qNum << ": " << curr->questionText << "\n";
        if (curr->type == MCQ && curr->choices) {
            // Display choices for MCQ.
            for (ChoiceNode* choice = curr->choices; choice != nullptr; choice = choice->next)
                cout << choice->letter << ". " << choice->choiceText << "\n";
        }
        cout << "Your answer: ";
        string answer;
        getline(cin, answer);
        curr->studentAnswer = answer;
        // Compare answers (for MCQ, TF, and WR all use string comparison)
        bool correct = caseInsensitiveCompare(answer, curr->correctAnswer);
        if (correct) {
            cout << "[Correct! You receive " << curr->pointValue << " points.]\n";
            earnedPoints += curr->pointValue;
        } else {
            cout << "[Incorrect. The correct answer is: " << curr->correctAnswer << "]\n";
        }
    }
    cout << "\nAssessment Complete.\nTotal earned points: " << earnedPoints 
         << " out of " << totalPoints << "\n";
}

#ifdef UNIT_TESTING
#include <cassert>
void testAssessment() {
    // Create a dummy question bank with 2 questions.
    QuestionNode* q1 = new QuestionNode;
    q1->id = 1;
    q1->type = MCQ;
    q1->questionText = "Which approach is used by C++?";
    q1->correctAnswer = "C";
    q1->pointValue = 10.0;
    q1->studentAnswer = "";
    q1->next = nullptr;
    
    // Create a linked list of choices for q1.
    ChoiceNode* choiceA = new ChoiceNode{'A', "Left-right", nullptr};
    ChoiceNode* choiceB = new ChoiceNode{'B', "Right-left", nullptr};
    ChoiceNode* choiceC = new ChoiceNode{'C', "Bottom-up", nullptr};
    ChoiceNode* choiceD = new ChoiceNode{'D', "Top-down", nullptr};
    choiceA->next = choiceB;
    choiceB->next = choiceC;
    choiceC->next = choiceD;
    q1->choices = choiceA;
    
    QuestionNode* q2 = new QuestionNode;
    q2->id = 2;
    q2->type = TF;
    q2->questionText = "In a flowchart, the switch diamond requires a true/false answer.";
    q2->correctAnswer = "false";
    q2->pointValue = 12.5;
    q2->studentAnswer = "";
    q2->next = nullptr;
    q2->choices = nullptr;
    q1->next = q2;
    
    // Simulate student answers.
    q1->studentAnswer = "c";
    q2->studentAnswer = "true";
    
    // Check using our caseInsensitiveCompare helper.
    assert(caseInsensitiveCompare(q1->studentAnswer, q1->correctAnswer) == true);
    assert(caseInsensitiveCompare(q2->studentAnswer, q2->correctAnswer) == false);
    
    // Clean up memory (in a real test, delete all nodes).
}
#endif

#ifndef UNIT_TESTING
int main() {
    // In production, the question bank would be built from Phase 1.
    // For demonstration, we'll create a small sample.
    QuestionNode* q1 = new QuestionNode;
    q1->id = 1;
    q1->type = MCQ;
    q1->questionText = "Which approach is used by C++?";
    q1->correctAnswer = "C";
    q1->pointValue = 10.0;
    q1->studentAnswer = "";
    q1->next = nullptr;
    
    // Set up MCQ choices.
    ChoiceNode* choiceA = new ChoiceNode{'A', "Left-right", nullptr};
    ChoiceNode* choiceB = new ChoiceNode{'B', "Right-left", nullptr};
    ChoiceNode* choiceC = new ChoiceNode{'C', "Bottom-up", nullptr};
    ChoiceNode* choiceD = new ChoiceNode{'D', "Top-down", nullptr};
    choiceA->next = choiceB;
    choiceB->next = choiceC;
    choiceC->next = choiceD;
    q1->choices = choiceA;
    
    QuestionNode* q2 = new QuestionNode;
    q2->id = 2;
    q2->type = TF;
    q2->questionText = "In a flowchart, the switch diamond requires a true/false answer.";
    q2->correctAnswer = "false";
    q2->pointValue = 12.5;
    q2->studentAnswer = "";
    q2->next = nullptr;
    q2->choices = nullptr;
    q1->next = q2;
    
    runAssessment(q1);
    
    // (Note: Memory cleanup is omitted for brevity.)
    return 0;
}
#endif

#ifdef UNIT_TESTING
int main() {
    testAssessment();
    cout << "All unit tests passed.\n";
    return 0;
}
#endif

