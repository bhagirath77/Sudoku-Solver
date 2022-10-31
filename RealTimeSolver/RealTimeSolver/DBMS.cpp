#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>
#include <vector>
using namespace std::chrono;
using namespace std;

struct author_id_name{
    string author_ki_id;
    string author_ka_naam;
};

struct book_id_name{
    string book_ki_id;
    string book_ka_naam;
};

struct book_author_id{
    string author_ki_id;
    string book_ki_id;
};

struct book_purchase{
    string book_ki_id;
    string purchase_date;
    int quantity;
};

struct author_ka_hash{
    int authoridindex;
    string authorid;
};

struct book_ka_hash{
    int bookid_to_authorid_idx;
    int bookid_in_bookpurchase_idx;
    int bookid_to_bookname_idx;
    string bookid;
};

struct author_ka_node{
    author_ka_hash data;
    author_ka_node* next;
    author_ka_node* prev;
    int num_ele;
};

struct book_ka_node{
    book_ka_hash data;
    book_ka_node* next;
    book_ka_node* prev;
    int num_ele;
};

bool push_in_author(author_ka_node** head_ref, author_ka_hash new_data, int cap)
{
    /* 1. allocate author_ka_node */
    author_ka_node* new_node = new author_ka_node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new author_ka_node as head
    and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if((*head_ref) == NULL){
        new_node->num_ele = 1;
    }
    
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    if((*head_ref) == NULL){
        new_node->num_ele = 1;
    }
    else{
        new_node->num_ele = new_node->next->num_ele + 1;
    }
    (*head_ref) = new_node;
    if(new_node->num_ele > cap){
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}

bool push_in_book(book_ka_node** head_ref, book_ka_hash new_data, int cap)
{
    /* 1. allocate author_ka_node */
    book_ka_node* new_node = new book_ka_node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new author_ka_node as head
    and previous as NULL */
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if((*head_ref) == NULL){
        new_node->num_ele = 1;
    }
    
 
    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    /* 5. move the head to point to the new node */
    if((*head_ref) == NULL){
        new_node->num_ele = 1;
    }
    else{
        new_node->num_ele = new_node->next->num_ele + 1;
    }
    (*head_ref) = new_node;
    if(new_node->num_ele > cap){
        return 1;
    }
    else{
        return 0;
    }
    return 0;
}

int main() {
	// your code goes here
	vector<string> author_id = {"An_Ch_0103","An_Da_0104","Ca_Sa_0319","Ca_Sa_0319","Jo_Ro_1018","Jo_Ro_1018","Jo_Ro_1018","Jo_Ro_1018","Jo_Ro_1018","La_Ch_1203","Ma_Mi_1313","Ma_Mi_1313","Pe_Wo_1623","Pe_Wo_1623","Vi_Ra_2218","Vi_Ra_2218"};
	vector<string> book_id = {"Aest_AC_0103","Self_AD_0104","Beyo_CS_0319","Song_CS_0319","Deat_JR_1018","Fant_JR_1018","Gobl_JR_1018","Phil_JR_1018","Pris_JR_1018","Mind_LC_1203","Emot_MM_1313","Soci_MM_1313","Aunt_PW_1623","Wode_PW_1623","Emer_VR_2218","Phan_VR_2218"};
	vector<string> author_name = {"Anjan Chatterjee","Antonio Damasio","Carl Safina","Carl Safina","Joanne K. Rowling","Joanne K. Rowling","Joanne K. Rowling","Joanne K. Rowling","Joanne K. Rowling","Lars Chittka","Marvin Minsky","Marvin Minsky","Pelham G. Wodehouse","Pelham G. Wodehouse","Vilayanur Ramachandran","Vilayanur Ramachandran"};
	vector<string> book_name = {"The Aesthetic Brain","Self Comes to Mind","Beyond Words: What Animals Think and Feel","Song for the Blue Ocean","Deathly Hallows_Harry Potter","Fantastic Beasts and Where to  Find Them","Goblet of Fire_Harry Potter","Philosopher’s Stone_Harry Potter","Prisoner of Azkaban_Harry Potter","The Mind of a Bee","Emotion Machine","Society of Mind","Aunts Aren’t Gentlemen","Wodehouse at the Wicket","The Emerging Mind","Phantoms in the Brain"};
	vector<string> book_purchase_id = {"Aest_AC_0103","Self_AD_0104","Beyo_CS_0319","Song_CS_0319","Deat_JR_1018","Fant_JR_1018","Gobl_JR_1018","Phil_JR_1018","Pris_JR_1018","Mind_LC_1203","Emot_MM_1313","Soci_MM_1313","Aunt_PW_1623","Wode_PW_1623","Emer_VR_2218","Phan_VR_2218"};
	vector<string> book_purchase_date = {"Sep 5, 2022","Sep 5, 2022","Sep 5, 2022","Sep 6, 2022","Sep 7, 2022","Sep 6, 2022","Sep 5, 2022","Sep 5, 2022","Sep 5, 2022","Sep 6, 2022","Sep 5, 2022","Sep 6, 2022","Sep 7, 2022","Sep 5, 2022","Sep 5, 2022","Sep 6, 2022"};
	vector<int> book_purchase_quantity = {1,1,2,2,5,5,5,5,5,2,1,1,4,4,1,3};
	vector<book_purchase> purchase_book(16);
	for(int i=0;i<16;i++){
	    purchase_book[i].book_ki_id = book_purchase_id[i];
	    purchase_book[i].purchase_date = book_purchase_date[i];
	    purchase_book[i].quantity = book_purchase_quantity[i];
	}
	vector<author_id_name> author_name_id;
	map<string, bool> authorid;
	for(int i=0;i<16;i++){
	    if(authorid[author_id[i]] == 0){
	        authorid[author_id[i]] = 1;
	        author_id_name ain;
	        ain.author_ki_id = author_id[i];
	        ain.author_ka_naam = author_name[i];
	        author_name_id.push_back(ain);
	    }
	}
    vector<book_author_id> author_book_id(16);
	for(int i=0;i<16;i++){
        author_book_id[i].author_ki_id = author_id[i];
        author_book_id[i].book_ki_id = book_id[i];
	}
	vector<book_id_name> book_name_id(16);
	for(int i=0;i<16;i++){
        book_name_id[i].book_ki_id = book_id[i];
        book_name_id[i].book_ka_naam = book_name[i];
	}
	
	map<int, author_ka_node*> authorid_ki_linearhashing;
	map<int, author_ka_node*> authorid_ki_extendiblehashing;
	for(int i=0;i<author_name_id.size();i++){
	    int func = (author_name_id[i].author_ki_id[0] + 32)%5;
	    author_ka_hash present_author;
	    present_author.authorid = author_name_id[i].author_ki_id;
	    present_author.authoridindex = i;
	    bool overflow = push_in_author(&authorid_ki_linearhashing[func], present_author, 5);
	    if(overflow){
	        author_ka_node* present = authorid_ki_linearhashing[func];
	        author_ka_node *linear_wala = NULL, *overflow_wala = NULL;
	        author_ka_node* head = present;
	        while(head!=NULL){
	            int fun = (head->data.authorid[0] + 32)%10;
	            if(fun < 5){
	                bool over = push_in_author(&linear_wala, head->data, 5);
	            }
	            else{
	                bool over = push_in_author(&overflow_wala, head->data, 5);
	            }
	            head = head->next;
	        }
	        authorid_ki_linearhashing[func] = linear_wala;
	        authorid_ki_linearhashing[func+5] = overflow_wala;
	    }
	}
	for(int i=0;i<author_name_id.size();i++){
	    int func = (author_name_id[i].author_ki_id[0] + 32)%5;
	    author_ka_hash present_author;
	    present_author.authorid = author_name_id[i].author_ki_id;
	    present_author.authoridindex = i;
	    bool overflow = push_in_author(&authorid_ki_extendiblehashing[func], present_author, 5);
	    if(overflow){
	        map<int, author_ka_node*> temp = authorid_ki_extendiblehashing;
	        for(auto j : temp){
	            author_ka_node* present = j.second;
    	        author_ka_node *linear_wala = NULL, *overflow_wala = NULL;
    	        author_ka_node* head = present;
    	        while(head!=NULL){
    	            int fun = (head->data.authorid[0] + 32)%10;
    	            if(fun < 5){
    	                bool over = push_in_author(&linear_wala, head->data, 5);
    	            }
    	            else{
    	                bool over = push_in_author(&overflow_wala, head->data, 5);
    	            }
    	            head = head->next;
	            }
	            authorid_ki_extendiblehashing[j.first] = linear_wala;
	            authorid_ki_extendiblehashing[j.first + 5] = overflow_wala;
	        }
	    }
	}
	map<int, book_ka_node*> bookid_ki_linearhashing;
	map<int, book_ka_node*> bookid_ki_extendiblehashing;
	for(int i=0;i<book_name_id.size();i++){
	    int func = (book_name_id[i].book_ki_id[0] + 32)%5;
	    book_ka_hash present_book;
	    present_book.bookid = book_name_id[i].book_ki_id;
	    present_book.bookid_to_bookname_idx = i;
	    present_book.bookid_to_authorid_idx = i;
	    present_book.bookid_in_bookpurchase_idx = i;
	    bool overflow = push_in_book(&bookid_ki_linearhashing[func], present_book, 5);
	    if(overflow){
	        book_ka_node* present = bookid_ki_linearhashing[func];
	        book_ka_node *linear_wala = NULL, *overflow_wala = NULL;
	        book_ka_node* head = present;
	        while(head!=NULL){
	            int fun = (head->data.bookid[0] + 32)%10;
	            if(fun < 5){
	                bool over = push_in_book(&linear_wala, head->data, 5);
	            }
	            else{
	                bool over = push_in_book(&overflow_wala, head->data, 5);
	            }
	            head = head->next;
	        }
	        bookid_ki_linearhashing[func] = linear_wala;
	        bookid_ki_linearhashing[func+5] = overflow_wala;
	    }
	}
	for(int i=0;i<book_name_id.size();i++){
	    int func = (book_name_id[i].book_ki_id[0] + 32)%5;
	    book_ka_hash present_book;
	    present_book.bookid = book_name_id[i].book_ki_id;
	    present_book.bookid_to_bookname_idx = i;
	    present_book.bookid_to_authorid_idx = i;
	    present_book.bookid_in_bookpurchase_idx = i;
	    bool overflow = push_in_book(&bookid_ki_extendiblehashing[func], present_book, 5);
	    if(overflow){
	        map<int, book_ka_node*> temp = bookid_ki_extendiblehashing;
	        for(auto j : temp){
	            book_ka_node* present = j.second;
    	        book_ka_node *linear_wala = NULL, *overflow_wala = NULL;
    	        book_ka_node* head = present;
    	        while(head!=NULL){
    	            int fun = (head->data.bookid[0] + 32)%10;
    	            if(fun < 5){
    	                bool over = push_in_book(&linear_wala, head->data, 5);
    	            }
    	            else{
    	                bool over = push_in_book(&overflow_wala, head->data, 5);
    	            }
    	            head = head->next;
	            }
	            bookid_ki_extendiblehashing[j.first] = linear_wala;
	            bookid_ki_extendiblehashing[j.first + 5] = overflow_wala;
	        }
	    }
	}

	// Q2 part A
	auto start_q2A = high_resolution_clock::now();
	string carl_kiId_;
	for(int i=0;i<author_name_id.size();i++){
	    if(author_name_id[i].author_ka_naam == "Carl Safina"){
	        carl_kiId_ = author_name_id[i].author_ki_id;
	        break;
	    }
	}
	vector<string> carlBook_Ids;
	for(int i=0;i<16;i++){
	    if(author_book_id[i].author_ki_id == carl_kiId_){
	        carlBook_Ids.push_back(author_book_id[i].book_ki_id);
	    }
	}
	vector<string> carl_Ki_Books;
	for(int i=0;i<carlBook_Ids.size();i++){
	    int carlBook = (carlBook_Ids[i][0] + 32)%10;
	    book_ka_node* check = bookid_ki_extendiblehashing[carlBook];
	    while(check != NULL){
	        if(check->data.bookid == carlBook_Ids[i]){
	            int idx = check->data.bookid_to_bookname_idx;
	            carl_Ki_Books.push_back(book_name_id[idx].book_ka_naam);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q2 Part A: Retrieve names of books written by \'Carl Safina\'\n";
	for(int i=0;i<carl_Ki_Books.size();i++){
	    cout<<i+1<<". "<<carl_Ki_Books[i]<<"\n";
	}
	auto end_q2A = high_resolution_clock::now();
	auto dur_q2A = duration_cast<microseconds>(end_q2A - start_q2A);
	cout<<"Execution time: "<<dur_q2A.count()<<" microseconds.\n\n";
	
	//Q2 part B
	auto start_q2B = high_resolution_clock::now();
	vector<string> author_ki_Ids, author_ke_Naam;
	for(int i=0;i<author_name_id.size();i++){
	    if(author_name_id[i].author_ka_naam[0] == 'A' || author_name_id[i].author_ka_naam[0] == 'P'){
	        author_ki_Ids.push_back(author_name_id[i].author_ki_id);
	        author_ke_Naam.push_back(author_name_id[i].author_ka_naam);
	    }
	}
	vector<vector<string>> authBook_Ids;
	for(int j=0;j<author_ki_Ids.size();j++){
    	for(int i=0;i<16;i++){
    	    if(author_book_id[i].author_ki_id == author_ki_Ids[j]){
    	        authBook_Ids.push_back({author_ki_Ids[j], author_ke_Naam[j], author_book_id[i].book_ki_id});
    	    }
    	}
	}
	for(int i=0;i<authBook_Ids.size();i++){
	    int authBook = (authBook_Ids[i][2][0] + 32)%10;
	    book_ka_node* check = bookid_ki_extendiblehashing[authBook];
	    while(check != NULL){
	        if(check->data.bookid == authBook_Ids[i][2]){
	            int idx = check->data.bookid_to_bookname_idx;
	            authBook_Ids[i][2] = book_name_id[idx].book_ka_naam;
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q2 Part B: Retrieve book names and author details of all books written by authors with names beginning with \'A\' or \'P\'\n";
	for(int i=0;i<authBook_Ids.size();i++){
	    cout<<i+1<<". Author ID: "<<authBook_Ids[i][0]<<", Author Name: "<<authBook_Ids[i][1]<<", Book Name: "<<authBook_Ids[i][2]<<"\n";
	}
	auto end_q2B = high_resolution_clock::now();
	auto dur_q2B = duration_cast<microseconds>(end_q2B - start_q2B);
	cout<<"Execution time: "<<dur_q2B.count()<<" microseconds.\n\n";
	
	//Q2 part C
	auto start_q2C = high_resolution_clock::now();
	vector<string> book_id_q;
	for(int i=0;i<16;i++){
	    if(purchase_book[i].quantity >= 5){
	        book_id_q.push_back(purchase_book[i].book_ki_id);
	    }
	}
	vector<int> book_idx_;
	for(int i=0;i<book_id_q.size();i++){
	    int authBook = (book_id_q[i][0] + 32)%10;
	    book_ka_node* check = bookid_ki_extendiblehashing[authBook];
	    while(check != NULL){
	        if(check->data.bookid == book_id_q[i]){
	            int idx = check->data.bookid_to_bookname_idx;
	            book_idx_.push_back(idx);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q2 Part C: Retrieve all books with >= 5 copies\n";
	for(int i=0;i<book_idx_.size();i++){
	    cout<<i+1<<". Book ID: "<<book_name_id[book_idx_[i]].book_ki_id<<", Book Name: "<<book_name_id[book_idx_[i]].book_ka_naam<<"\n";
	}
	auto end_q2C = high_resolution_clock::now();
	auto dur_q2C = duration_cast<microseconds>(end_q2C - start_q2C);
	cout<<"Execution time: "<<dur_q2C.count()<<" microseconds.\n\n";
	
	//Q2 part D
	auto start_q2D = high_resolution_clock::now();
	map<string, vector<int>> authdates;
	for(int i=0;i<author_name_id.size();i++){
	    authdates[author_name_id[i].author_ki_id] = {0,0,0};
	}
	for(int i=0;i<16;i++){
	    int ix = 0;
	    if(purchase_book[i].purchase_date[4] == '6'){
	        ix = 1;
	    }
	    else if(purchase_book[i].purchase_date[4] == '7'){
	        ix = 2;
	    }
	    authdates[author_book_id[i].author_ki_id][ix] = 1;
	}
	vector<string> authall;
	for(auto i : authdates){
	    bool all = 1;
	    for(int j=0;j<3;j++){
	        if(i.second[j] == 0){
	            all = 0;
	            break;
	        }
	    }
	    if(all){
	        authall.push_back(i.first);
	    }
	}
	vector<string> authorall;
	for(int i=0;i<authall.size();i++){
	    int carlBook = (authall[i][0] + 32)%5;
	    author_ka_node* check = authorid_ki_extendiblehashing[carlBook];
	    while(check != NULL){
	        if(check->data.authorid == authall[i]){
	            int idx = check->data.authoridindex;
	            authorall.push_back(author_name_id[idx].author_ka_naam);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q2 Part D: Retrieve author_names whose books have been purchased across all dates available on the purchase table\n";
	for(int i=0;i<authorall.size();i++){
	    cout<<i+1<<". "<<authorall[i]<<"\n";
	}
	auto end_q2D = high_resolution_clock::now();
	auto dur_q2D = duration_cast<microseconds>(end_q2D - start_q2D);
	cout<<"Execution time: "<<dur_q2D.count()<<" microseconds.\n\n";

	//Q2 part E
	auto start_q2E = high_resolution_clock::now();
	vector<string> authsingle;
	map<string, bool> chkauth;
	for(int i=0;i<16;i++){
	    if(purchase_book[i].quantity == 1){
			if(chkauth[author_book_id[i].author_ki_id] == 0){
				authsingle.push_back(author_book_id[i].author_ki_id);
				chkauth[author_book_id[i].author_ki_id] = 1;
			}
	    }
	}
	vector<string> authorsingle;
	for(int i=0;i<authsingle.size();i++){
	    int carlBook = (authsingle[i][0] + 32)%5;
	    author_ka_node* check = authorid_ki_extendiblehashing[carlBook];
	    while(check != NULL){
	        if(check->data.authorid == authsingle[i]){
	            int idx = check->data.authoridindex;
	            authorsingle.push_back(author_name_id[idx].author_ka_naam);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q2 Part E: For the books that have just a single copy in the database, retrieve the author_names\n";
	for(int i=0;i<authorsingle.size();i++){
	    cout<<i+1<<". "<<authorsingle[i]<<"\n";
	}
	auto end_q2E = high_resolution_clock::now();
	auto dur_q2E = duration_cast<microseconds>(end_q2E - start_q2E);
	cout<<"Execution time: "<<dur_q2E.count()<<" microseconds.\n\n";
	
	// Q3 part A
	auto start_q3A = high_resolution_clock::now();
	string carl_kiId;
	for(int i=0;i<author_name_id.size();i++){
	    if(author_name_id[i].author_ka_naam == "Carl Safina"){
	        carl_kiId = author_name_id[i].author_ki_id;
	        break;
	    }
	}
	vector<string> carlBookIds;
	for(int i=0;i<16;i++){
	    if(author_book_id[i].author_ki_id == carl_kiId){
	        carlBookIds.push_back(author_book_id[i].book_ki_id);
	    }
	}
	vector<string> carlKiBooks;
	for(int i=0;i<carlBookIds.size();i++){
	    int carlBook = (carlBookIds[i][0] + 32)%5;
	    book_ka_node* check = bookid_ki_linearhashing[carlBook];
	    while(check != NULL){
	        if(check->data.bookid == carlBookIds[i]){
	            int idx = check->data.bookid_to_bookname_idx;
	            carlKiBooks.push_back(book_name_id[idx].book_ka_naam);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q3 Part A: Retrieve names of books written by \'Carl Safina\'\n";
	for(int i=0;i<carlKiBooks.size();i++){
	    cout<<i+1<<". "<<carlKiBooks[i]<<"\n";
	}
	auto end_q3A = high_resolution_clock::now();
	auto dur_q3A = duration_cast<microseconds>(end_q3A - start_q3A);
	cout<<"Execution time: "<<dur_q3A.count()<<" microseconds.\n\n";
	
	//Q3 part B
	auto start_q3B = high_resolution_clock::now();
	vector<string> author_kiIds, author_keNaam;
	for(int i=0;i<author_name_id.size();i++){
	    if(author_name_id[i].author_ka_naam[0] == 'A' || author_name_id[i].author_ka_naam[0] == 'P'){
	        author_kiIds.push_back(author_name_id[i].author_ki_id);
	        author_keNaam.push_back(author_name_id[i].author_ka_naam);
	    }
	}
	vector<vector<string>> authBookIds;
	for(int j=0;j<author_kiIds.size();j++){
    	for(int i=0;i<16;i++){
    	    if(author_book_id[i].author_ki_id == author_kiIds[j]){
    	        authBookIds.push_back({author_kiIds[j], author_keNaam[j], author_book_id[i].book_ki_id});
    	    }
    	}
	}
	for(int i=0;i<authBookIds.size();i++){
	    int authBook = (authBookIds[i][2][0] + 32)%10;
		if(authBook >= 5 && authBook != 7){
			authBook %= 5;
		}
	    book_ka_node* check = bookid_ki_linearhashing[authBook];
	    while(check != NULL){
	        if(check->data.bookid == authBookIds[i][2]){
	            int idx = check->data.bookid_to_bookname_idx;
	            authBookIds[i][2] = book_name_id[idx].book_ka_naam;
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q3 Part B: Retrieve book names and author details of all books written by authors with names beginning with \'A\' or \'P\'\n";
	for(int i=0;i<authBookIds.size();i++){
	    cout<<i+1<<". Author ID: "<<authBookIds[i][0]<<", Author Name: "<<authBookIds[i][1]<<", Book Name: "<<authBookIds[i][2]<<"\n";
	}
	auto end_q3B = high_resolution_clock::now();
	auto dur_q3B = duration_cast<microseconds>(end_q3B - start_q3B);
	cout<<"Execution time: "<<dur_q3B.count()<<" microseconds.\n\n";
	
	//Q3 part C
	auto start_q3C = high_resolution_clock::now();
	vector<string> bookid_q;
	for(int i=0;i<16;i++){
	    if(purchase_book[i].quantity >= 5){
	        bookid_q.push_back(purchase_book[i].book_ki_id);
	    }
	}
	vector<int> book_idx;
	for(int i=0;i<bookid_q.size();i++){
	    int authBook = (bookid_q[i][0] + 32)%5;
	    book_ka_node* check = bookid_ki_linearhashing[authBook];
	    while(check != NULL){
	        if(check->data.bookid == bookid_q[i]){
	            int idx = check->data.bookid_to_bookname_idx;
	            book_idx.push_back(idx);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q3 Part C: Retrieve all books with >= 5 copies\n";
	for(int i=0;i<book_idx.size();i++){
	    cout<<i+1<<". Book ID: "<<book_name_id[book_idx[i]].book_ki_id<<", Book Name: "<<book_name_id[book_idx[i]].book_ka_naam<<"\n";
	}
	auto end_q3C = high_resolution_clock::now();
	auto dur_q3C = duration_cast<microseconds>(end_q3C - start_q3C);
	cout<<"Execution time: "<<dur_q3C.count()<<" microseconds.\n\n";
	
	//Q3 part D
	auto start_q3D = high_resolution_clock::now();
	map<string, vector<int>> auth_dates;
	for(int i=0;i<author_name_id.size();i++){
	    auth_dates[author_name_id[i].author_ki_id] = {0,0,0};
	}
	for(int i=0;i<16;i++){
	    int ix = 0;
	    if(purchase_book[i].purchase_date[4] == '6'){
	        ix = 1;
	    }
	    else if(purchase_book[i].purchase_date[4] == '7'){
	        ix = 2;
	    }
	    auth_dates[author_book_id[i].author_ki_id][ix] = 1;
	}
	vector<string> auth_all;
	for(auto i : auth_dates){
	    bool all = 1;
	    for(int j=0;j<3;j++){
	        if(i.second[j] == 0){
	            all = 0;
	            break;
	        }
	    }
	    if(all){
	        auth_all.push_back(i.first);
	    }
	}
	vector<string> author_all;
	for(int i=0;i<auth_all.size();i++){
	    int carlBook = (auth_all[i][0] + 32)%5;
	    author_ka_node* check = authorid_ki_linearhashing[carlBook];
	    while(check != NULL){
	        if(check->data.authorid == auth_all[i]){
	            int idx = check->data.authoridindex;
	            author_all.push_back(author_name_id[idx].author_ka_naam);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q3 Part D: Retrieve author_names whose books have been purchased across all dates available on the purchase table\n";
	for(int i=0;i<author_all.size();i++){
	    cout<<i+1<<". "<<author_all[i]<<"\n";
	}
	auto end_q3D = high_resolution_clock::now();
	auto dur_q3D = duration_cast<microseconds>(end_q3D - start_q3D);
	cout<<"Execution time: "<<dur_q3D.count()<<" microseconds.\n\n";

	//Q3 part E
	auto start_q3E = high_resolution_clock::now();
	vector<string> auth_single;
	map<string, bool> chk_auth;
	for(int i=0;i<16;i++){
	    if(purchase_book[i].quantity == 1){
			if(chk_auth[author_book_id[i].author_ki_id] == 0){
				auth_single.push_back(author_book_id[i].author_ki_id);
				chk_auth[author_book_id[i].author_ki_id] = 1;
			}
	    }
	}
	vector<string> author_single;
	for(int i=0;i<auth_single.size();i++){
	    int carlBook = (auth_single[i][0] + 32)%5;
	    author_ka_node* check = authorid_ki_linearhashing[carlBook];
	    while(check != NULL){
	        if(check->data.authorid == auth_single[i]){
	            int idx = check->data.authoridindex;
	            author_single.push_back(author_name_id[idx].author_ka_naam);
	            break;
	        }
	        check = check->next;
	    }
	}
	cout<<"Q3 Part E: For the books that have just a single copy in the database, retrieve the author_names\n";
	for(int i=0;i<author_single.size();i++){
	    cout<<i+1<<". "<<author_single[i]<<"\n";
	}
	auto end_q3E = high_resolution_clock::now();
	auto dur_q3E = duration_cast<microseconds>(end_q3E - start_q3E);
	cout<<"Execution time: "<<dur_q3E.count()<<" microseconds.\n\n";
	return 0;
}
