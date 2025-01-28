#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const string& val)
{
  string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw invalid_argument("Bad location");
  }
  *ptr = val;
}

string& ULListStr::get(size_t loc)
{
  string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw invalid_argument("Bad location");
  }
  return *ptr;
}

string const & ULListStr::get(size_t loc) const
{
  string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const string& val){
  if(tail_==nullptr){
  Item* newItem = new Item();
  newItem->val[0]=val;
  newItem->first=0;
  newItem->last=1;
  head_=newItem;
  tail_=newItem;

}

else if (tail_->last==ARRSIZE){
  Item* newItem = new Item();
  newItem->val[0]=val;
  newItem->first=0;
  newItem->last=1;
  newItem->prev=tail_;
  tail_->next=newItem;
  tail_=newItem;
}

else {
  tail_->val[tail_->last]=val;
  tail_->last++;
  
}

size_++;

}

void ULListStr::push_front(const string& val){
if(head_==nullptr){
  Item* newItem = new Item();
  newItem->val[ARRSIZE-1]=val;
  newItem->first=ARRSIZE-1;
  newItem->last=ARRSIZE;
  head_=newItem;
  tail_=newItem;

}

else if (head_->first==0){
  Item* newItem = new Item();
  newItem->val[ARRSIZE-1]=val;
  newItem->first=ARRSIZE-1;
  newItem->last=ARRSIZE;
  newItem->next=head_;
  head_->prev=newItem;
  head_=newItem;
}

else {
  head_->first--;
  head_->val[head_->first]=val;
}

size_++;

}

void ULListStr::pop_back(){
  if (empty()){
    return;
  }

  tail_->last--;
 

  if(tail_->first==tail_->last){
    Item* temp=tail_;
    tail_=tail_->prev;

    if (tail_!=nullptr){
      tail_->next=nullptr;
    }

    else{
      head_=nullptr;
    }

    delete temp;
  }

  size_--;
}

void ULListStr::pop_front(){
  if(empty()){
    return;
  }

  head_->first++;
  

  if (head_->first==head_->last){
    Item* temp=head_;
    head_=head_->next;

    if (head_!=nullptr){
      head_->prev=nullptr;
    }

    else{
      tail_=nullptr;
    }

    delete temp;
  }
  size_--;
}

string const & ULListStr::back() const{
  if(!empty()){
  return tail_->val[tail_->last-1];
}
}

string const & ULListStr::front() const{
  if (!empty()){
    return head_->val[head_->first];
  }
}



string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc>=size_){
    return nullptr;
  }

  size_t count=0;
  Item* curr=head_;

  while (curr!=nullptr){
    size_t nodeSize= curr->last - curr->first;
    count=count+nodeSize;
    if (loc<count){
      size_t localIndex=curr->first + (loc - (count - nodeSize));
      return &curr->val[localIndex];
    }
    
    curr=curr->next;
  }

  return nullptr;


}