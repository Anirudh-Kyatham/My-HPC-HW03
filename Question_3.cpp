#include<iostream>
#include<cmath>

/*
here the time complexity is O(n)
*/
struct linklist
{
    int val;
    linklist* next;
    linklist(int val = 0) :val(val), next(nullptr) {}
};

linklist* solution(linklist* n1, linklist* n2) {
    linklist* res = new linklist(0);
    linklist* curr{ res };
    int carry{ 0 };
    while (n1 != nullptr || n2 != nullptr || carry != 0) {
        int sum{ 0 };
        if (n1 != nullptr) {
            sum += n1->val;
            n1 = n1->next;
        }
        if (n2 != nullptr) {
            sum += n2->val;
            n2 = n2->next;
        }
        sum += carry;

        curr->next = new linklist(sum % 10);
        curr = curr->next;
        carry = sum / 10;
    }

    return res->next;
}

linklist* numtoll(int val) {
    linklist* resnode = new linklist(val % 10);
    linklist* run = resnode;
    while (val != 0) {
        run->next = new linklist(val % 10);
        val /= 10;
        run = run->next;
    }

    return resnode->next;
}

void printer(linklist* n) {
    while (n != nullptr)
    {
        std::cout << n->val << " ";
        n = n->next;
    }
    std::cout << std::endl;

}

int main(int argc, char const* argv[]) {
    int val1 = 342;
    int val2 = 465;
    linklist* nv1 = numtoll(val1);
    linklist* nv2 = numtoll(val2);

    linklist* ans = solution(nv1, nv2);
    printer(ans);


    return 0;
}