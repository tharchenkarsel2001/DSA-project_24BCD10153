#include <stdio.h>
#define MAX 100
void display(int arr[],int size){
	if(size==0){
		printf("Array is empty.\n");
     
	 return;
	
	}
	printf("element of the array :");
	for (int i=0; i<size; i++){
		printf("%d", arr[i]);
	}
	printf("\n");
}
void insert(int arr[],int *size,int element,int position){
	if (*size>=MAX){
		printf("Array is full,cannot insert more.\n");
	return;	
	}
	
	if (position<0||position>*size){
		printf("invalid position.Please enter a valid position.\n");
		return;
	}
	for (int i=*size;i>position;i--){
		arr[i]=arr[i-1];
	}
	arr[position]=element;
	(*size)++;
	
	
}

void delete_element(int arr[],int*size,int position){
	if (*size==0){
		printf("Array is empty,cannot delete element.\n");
		return;
	}
	if (position<0||position>=*size){
		printf("invalid position.Please enter valid position.\n");
		return;
	}
	for (int i=position;i<*size-1;i++){
		arr[i]=arr[i+1];
	}
	(*size)--;
	printf("Element deleted sucessfully.\n");
}
int main(){
	int arr[MAX];
	int size=0,choice,element,position;
	
	while(1){
		printf("\nMenu:\n");
		printf("\n1.Insert an element:\n");
		printf("\n2.delete an element :\n");
		printf("\n3.display all elements:\n");
		printf("\n4.Exit.\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice){#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
// --------------------- Queue for Voters ---------------------
typedef struct Voter {
    int id;
    struct Voter* next;
} Voter;
Voter *front = NULL, *rear = NULL;
void enqueue(int id) {
    Voter* newVoter = (Voter*)malloc(sizeof(Voter));
    newVoter->id = id;
    newVoter->next = NULL;
    if (rear == NULL)
        front = rear = newVoter;
    else {
        rear->next = newVoter;
        rear = newVoter;
    }
    printf("Voter with ID %d registered.\n", id);
}
int dequeue() {
    if (front == NULL)
        return -1;
    int id = front->id;
    Voter* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
    return id;
}
// ------------------ Linked List for Candidates ------------------
typedef struct Candidate {
    int id;
    char name[NAME_LENGTH];
    int votes;
    struct Candidate* next;
} Candidate;
Candidate* candidateHead = NULL;
void addCandidate(int id, char name[]) {
    Candidate* newNode = (Candidate*)malloc(sizeof(Candidate));
    newNode->id = id;
    strcpy(newNode->name, name);
    newNode->votes = 0;
    newNode->next = candidateHead;
    candidateHead = newNode;
}
void displayCandidates() {
    Candidate* temp = candidateHead;
    printf("\n--- Candidates List ---\n");
    while (temp != NULL) {
        printf("ID: %d | Name: %s | Votes: %d\n", temp->id, temp->name, temp->votes);
        temp = temp->next;
    }
}

// ------------------ Tree for Vote Results ------------------
typedef struct VoteNode {
    int candidateId;
    int voteCount;
    struct VoteNode* left;
    struct VoteNode* right;
} VoteNode;
VoteNode* root = NULL;
VoteNode* insertVote(VoteNode* node, int candidateId) {
    if (node == NULL) {
        VoteNode* newNode = (VoteNode*)malloc(sizeof(VoteNode));
        newNode->candidateId = candidateId;
        newNode->voteCount = 1;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (candidateId == node->candidateId)
        node->voteCount++;
    else if (candidateId < node->candidateId)
        node->left = insertVote(node->left, candidateId);
    else
        node->right = insertVote(node->right, candidateId);
    return node;
}
void displayResults(VoteNode* node) {
    if (node == NULL) return;
    displayResults(node->left);
    printf("Candidate ID %d got %d votes.\n", node->candidateId, node->voteCount);
    displayResults(node->right);}
// ------------------ Vote Functionality ------------------
void castVote() {
    if (front == NULL) {
        printf("No voters in queue.\n");
        return;
    }
    int voterId = dequeue();
    int choice;
    Candidate* temp = candidateHead;
    printf("\nVoter %d voting...\n", voterId);
    displayCandidates();
    printf("Enter candidate ID to vote: ");
    scanf("%d", &choice);

    while (temp != NULL) {
        if (temp->id == choice) {
            temp->votes++;
            root = insertVote(root, choice);
            printf("Vote cast successfully by voter %d.\n", voterId);
            return;
        }
        temp = temp->next;
    }
    printf("Invalid candidate ID.\n");
}
// ------------------ Main Program ------------------
int main() {
    int ch, id;
    char name[NAME_LENGTH];
    printf("=== Digital Voting System ===\n");
    while (1) {
        printf("\n1. Add Candidate\n2. Register Voter\n3. Cast Vote\n4. Show Candidates\n5. Show Results\n6. Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter candidate ID: ");
                scanf("%d", &id);
                printf("Enter candidate name: ");
                scanf(" %[^\n]s", name);
                addCandidate(id, name);
                break;
            case 2:
                printf("Enter voter ID: ");
                scanf("%d", &id);
                enqueue(id);
                break;
            case 3:
                castVote();
                break;
            case 4:
                displayCandidates();
                break;
            case 5:
                printf("\n--- Voting Results ---\n");
                displayResults(root);
                break;
            case 6:
                printf("Exiting voting system.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

			case 1:
				printf("Enter the element to insert:");
				scanf("%d",&element);
				printf("Enter the position to insert(0-based index):");
				scanf("%d",&position);
				insert(arr,&size,element,position);
				break;
				case 2:
					printf("Enter the position of element to delete(0-based index:)");
					scanf("%d",&position);
					delete_element(arr,&size,position);
					break;
					case 3:
						display(arr,size);
						break;
						case 4:
							printf("Exiting the program.\n");
							return 0;
							default:
								printf("invalid choice.Please try again.\n");
								
		}
	}
	
}














