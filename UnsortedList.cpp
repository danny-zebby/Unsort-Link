

template<class T>
UnsortedList<T>::UnsortedList() {
    length = 0;
    head = nullptr;
    curr = nullptr;
}

template<class T>
void UnsortedList<T>::MakeEmpty() {
    while(head!= nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }//head= nullptr;
}

template<class T>
bool UnsortedList<T>::IsFull() const {
    try{
        Node* temp = new Node;
        delete temp;
    }catch(std::bad_alloc error){
        return true;}
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {
    Node* temp = head;
    while(temp != nullptr){
        if(temp->value == someItem)
            return true;
        temp = temp->next;}
    return false;
}

template<class T>
void UnsortedList<T>::PutItem(T item) {
    Node* put = new Node;
    put->value = item;
    put->next = head;
    head = put;
    ++length;
}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {
    Node* temp = head;
    Node* prev = head;
    while(temp != nullptr){
        if(temp->value == item){
            prev->next = temp->next;
            delete temp;
            --length;
        }
        prev = temp;
        temp = temp->next;
    }

}

template<class T>
void UnsortedList<T>::ResetIterator() {
    curr = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    curr = curr->next;
    return curr->value;
}
