// SNUverse.cpp
#include "SNUverse.h"
#include <iostream>
#include <utility> //You may use pair<T1, T2> if you want.

using namespace std;

//Account Implementation
Account::Account(const string& ID) : ID(ID) {}

string Account::Get_ID() const{ 
    return ID;
}

vector<string> Account::Get_followingList() const {
    return FollowingList;
}

vector<string> Account::Get_followerList() const {
    return FollowerList;
}


bool Account::Add_following(const string& dest_ID){ //add ID to the end of the following list
    //TODO
    if (FollowingList.empty()) {
        FollowingList.push_back(dest_ID);
        return true;
    }
    else {
        for (int i = 0; i < FollowingList.size(); i++) {
            if (FollowingList[i] == dest_ID) {
                return false;
            }
        }
        FollowingList.push_back(dest_ID);
        return true;
    }
}


bool Account::Add_follower(const string& dest_ID){ //add ID to the end of the follower list
    //TODO
    if (FollowerList.empty()) {
        FollowerList.push_back(dest_ID);
        return true;
    }
    else {
        for (int i = 0; i < FollowerList.size(); i++) {
            if (FollowerList[i] == dest_ID) {
                return false;
            }
        }
        FollowerList.push_back(dest_ID);
        return true;
    }
}

bool Account::Delete_following(const string& dest_ID){ //delete ID from following list
    //TODO
    if (FollowingList.empty()) {
        return false;
    }
    else {
        for (int i = 0; i < FollowingList.size(); i++) {
            if (FollowingList[i] == dest_ID) {
                FollowingList.erase(FollowingList.begin() + i);
                return true;
            }
        }
        return false;
    }
}

bool Account::Delete_follower(const string& dest_ID){ //delete ID from follower list
    //TODO
    if (FollowerList.empty()) {
        return false;
    }
    else {
        for (int i = 0; i < FollowerList.size(); i++) {
            if (FollowerList[i] == dest_ID) {
                FollowerList.erase(FollowerList.begin() + i);
                return true;
            }
        }
        return false;
    }
}


//SNUverse implementation
SNUverse::SNUverse() {}

SNUverse::~SNUverse() {}

void SNUverse::Create_account(const string& ID) { //create account with ID
    //TODO
    if (AccountList.empty()) {
        AccountList.push_back(Account(ID));
    }
    else {
        //use iterator
        vector<Account>::iterator it = Get_account(ID);
        if (it != AccountList.end()) {
            cout << "ID: " << ID << " already exists." << endl;
            return;
        }
        else {
            AccountList.push_back(Account(ID));
        }
    }
}

void SNUverse::Delete_account(const string& ID) { //delete account with ID
    //TODO
    vector<Account>::iterator it = Get_account(ID);
    if (it == AccountList.end()) {
        cout << "ID: " << ID << " does not exist." << endl;
        return;
    }
    else {
        if (it->Get_ID() == ID) {
                for (int j = 0; j < it->Get_followingList().size(); j++) {
                    for (int k = 0; k < AccountList.size(); k++) {
                        if (AccountList[k].Get_ID() == it->Get_followingList()[j]) {
                            AccountList[k].Delete_follower(ID);
                        }
                    }
                }
                for (int j = 0; j < it->Get_followerList().size(); j++) {
                    for (int k = 0; k < AccountList.size(); k++) {
                        if (AccountList[k].Get_ID() == it->Get_followerList()[j]) {
                            AccountList[k].Delete_following(ID);
                        }
                    }
                }
                AccountList.erase(it);
                return;
            }
        }
        cout << "ID: " << ID << " does not exist." << endl;
   }

void SNUverse::Follow(const string& src_ID, const string& dest_ID) { //If A follows B, In A's account: B is following, In B's account: A is follower
    //TODO
    vector<Account>::iterator src_it = Get_account(src_ID);
    vector<Account>::iterator dest_it = Get_account(dest_ID);
    if (src_it == AccountList.end() || dest_it == AccountList.end()) {
        return;
    }
    else {
        src_it->Add_following(dest_ID);
        dest_it->Add_follower(src_ID);
        return;
    }
}


void SNUverse::Unfollow(const string& src_ID, const string& dest_ID) { 
    //TODO
    vector<Account>::iterator src_it = Get_account(src_ID);
    vector<Account>::iterator dest_it = Get_account(dest_ID);
    if (src_it == AccountList.end() || dest_it == AccountList.end()) {
        return;
    }
    else {
        src_it->Delete_following(dest_ID);
        dest_it->Delete_follower(src_ID);
        return;
    }
}

void SNUverse::Recommend_friend(const string& src_ID) { //print recommended friend list of src_ID
    //TODO

    vector<Account>::iterator src_it = Get_account(src_ID);

    if (src_it == AccountList.end()) {
        return;
    }
    else {
        if (src_it->Get_followingList().empty()) {
            cout << "No recommendation for " << src_ID << "." << endl;
            return;
        }
        else {
            // temporary vectors for following list and recommended friends
            vector<string> temp_following = src_it->Get_followingList();
            vector<string> temp_recommended;
            for (int j = 0; j < temp_following.size(); j++) {
                for (int k = 0; k < AccountList.size(); k++) {
                    if (AccountList[k].Get_ID() == temp_following[j]) { //AccountList[k] is the account of the following of src_ID
                        for (int l = 0; l < AccountList[k].Get_followingList().size(); l++) { //iterate through the following list of AccountList[k]
                            string temp = AccountList[k].Get_followingList()[l];
                            if (temp == src_ID){
                                continue; }
                            else {
                                bool flag = true;
                                for (int m = 0; m < temp_recommended.size(); m++) {
                                    if (temp_recommended[m] == temp) {
                                        flag = false;
                                        break;
                                    }
                                }
                                if (flag) {
                                    for (int n = 0; n < temp_following.size(); n++) {
                                        if (temp_following[n] == temp) {
                                            break;
                                        }
                                        else if (n == temp_following.size() - 1) {
                                            temp_recommended.push_back(temp);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (temp_recommended.empty()) {
                cout << "No recommendation for " << src_ID << "." << endl;
                return;
            }
            else {
                cout << src_ID << ": ";
                for (int j = 0; j < temp_recommended.size(); j++) {
                    cout << temp_recommended[j] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
}


void SNUverse::Common_friends(const string& src_ID, const string& dest_ID){ //print common friends of src_ID and dest_ID
    //TODO

    vector<Account>::iterator src_it = Get_account(src_ID);
    vector<Account>::iterator dest_it = Get_account(dest_ID);

    if (src_it == AccountList.end() || dest_it == AccountList.end()) {
        return;
    }
    else {
        if (src_it->Get_followingList().empty() || dest_it->Get_followingList().empty()) {
            cout << "No common friends between " << src_ID << " and " << dest_ID << "." << endl;
            return;
        }
        else {
            vector<string> temp_src_following = src_it->Get_followingList();
            vector<string> temp_dest_following = dest_it->Get_followingList();
            vector<string> temp_common_friends;
            for (int i = 0; i < temp_src_following.size(); i++) {
                for (int j = 0; j < temp_dest_following.size(); j++) {
                    if (temp_src_following[i] == temp_dest_following[j]) {
                        temp_common_friends.push_back(temp_src_following[i]);
                    }
                }
            }
            if (temp_common_friends.empty()) {
                cout << "No common friends between " << src_ID << " and " << dest_ID << "." << endl;
                return;
            }
            else {
                cout << src_ID << " & " << dest_ID << ": ";
                for (int i = 0; i < temp_common_friends.size(); i++) {
                    cout << temp_common_friends[i] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
}

void SNUverse::Print(int mode) const{

    //TODO
    if (AccountList.empty()) {
        return;
    }
    else {
        if (mode == 0) {
            for (int i = 0; i < AccountList.size(); i++) {
                if (AccountList[i].Get_followingList().empty()) {
                    cout << AccountList[i].Get_ID() << " has no followings." << endl;
                }
                else {
                    cout << AccountList[i].Get_ID() << ": ";
                    for (int j = 0; j < AccountList[i].Get_followingList().size(); j++) {
                        cout << AccountList[i].Get_followingList()[j] << " ";
                    }
                    cout << endl;
                }
            }
        }
        else if (mode == 1) {
            for (int i = 0; i < AccountList.size(); i++) {
                if (AccountList[i].Get_followerList().empty()) {
                    cout << AccountList[i].Get_ID() << " has no followers." << endl;
                }
                else {
                    cout << AccountList[i].Get_ID() << ": ";
                    for (int j = 0; j < AccountList[i].Get_followerList().size(); j++) {
                        cout << AccountList[i].Get_followerList()[j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

}

bool SNUverse::isReachable(const string& src_ID, const string& dest_ID) const { //through traversing following list
    //TODO
    //Base cases:
    vector<Account>::const_iterator src_it = Get_const_account(src_ID);
    vector<Account>::const_iterator dest_it = Get_const_account(dest_ID);
    if ((src_it == AccountList.end()) or (dest_it == AccountList.end())){
        return false;
    }

    if (src_ID == dest_ID) {
        return true;  // Same account, reachable
    }

    // Initialize variables for BFS:
    std::vector<string> toVisit = {src_ID};
    std::vector<bool> visited(AccountList.size(), false);
    visited[Get_index(src_ID)] = true;  // Mark source as visited

    // Simulate BFS using a vector for toVisit:
    while (!toVisit.empty()) {
        std::vector<string> nextLevel;  // Accounts for the next level

        for (const string& currentID : toVisit) {
            if (currentID == dest_ID) {
                return true;
            }

            // Explore neighbors:
            vector<Account>::const_iterator crt_it = Get_const_account(currentID);
            for (const string& followingID : crt_it->Get_followingList()) {
                if (!visited[Get_index(followingID)]) {
                    nextLevel.push_back(followingID);
                    visited[Get_index(followingID)] = true;
                }
            }
        }
        // Move to the next level:
        toVisit = nextLevel;
    }
    // Destination not reachable:
    return false;
}

int SNUverse::Distance(const string& src_ID, const string& dest_ID) const { //through traversing following list
    //TODO

    // Base cases:
    vector<Account>::const_iterator src_it = Get_const_account(src_ID);
    vector<Account>::const_iterator dest_it = Get_const_account(dest_ID);
    if ((src_it == AccountList.end()) or (dest_it == AccountList.end())){
        return -1;
    }

    if (src_ID == dest_ID) {
        return 0;  // Same account, distance is 0
    }

    // Initialize variables for BFS:
    std::vector<string> toVisit = {src_ID};
    std::vector<bool> visited(AccountList.size(), false);
    visited[Get_index(src_ID)] = true;  // Mark source as visited

    int distance = 0;

    // Simulate BFS using a vector for toVisit:
    while (!toVisit.empty()) {
        std::vector<string> nextLevel;  // Accounts for the next level

        for (const string& currentID : toVisit) {
            if (currentID == dest_ID) {
                return distance;
            }

            // Explore neighbors:
            vector<Account>::const_iterator crt_it = Get_const_account(currentID);
            for (const string& followingID : crt_it->Get_followingList()) {
                if (!visited[Get_index(followingID)]) {
                    nextLevel.push_back(followingID);
                    visited[Get_index(followingID)] = true;
                }
            }
        }

        // Move to the next level:
        toVisit = nextLevel;
        distance++;
    }

    // Destination not reachable:
    return -1;

}

vector<Account>::iterator SNUverse::Get_account(const string& ID){ //return normal iterator
    //TODO
if (AccountList.empty()) {
        return AccountList.end();
    }
    else {
        for (int i = 0; i < AccountList.size(); i++) {
            if (AccountList[i].Get_ID() == ID) {
                return AccountList.begin() + i;
            }
        }
        return AccountList.end();
    }
}

vector<Account>::const_iterator SNUverse::Get_const_account(const string& ID) const{ //return the const iterator
    //TODO
if (AccountList.empty()) {
        return AccountList.end();
    }
    else {
        for (int i = 0; i < AccountList.size(); i++) {
            if (AccountList[i].Get_ID() == ID) {
                return AccountList.begin() + i;
            }
        }
        return AccountList.end();
    }
}

int SNUverse::Get_index(const string& ID) const {
    //TODO
    if (AccountList.empty()) {
        return -1;
    }
    else {
        for (int i = 0; i < AccountList.size(); i++) {
            if (AccountList[i].Get_ID() == ID) {
                return i;
            }
        }
        return -1;
    }

}