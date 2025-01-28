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
  if (!tail_||tail_->last==ARRSIZE){
    Item* newItem=new Item();
    if(tail_!=nullptr){
      tail_->next=newItem;
      newItem->prev=tail_;
    }
    tail_=newItem;
    if (head_==nullptr){
      head_=tail_;
    }
  }
  tail_->val[tail_->last]=val;
  tail_->last++;
  size_++;
}

void ULListStr::push_front(const string& val){
if (!head_||head_->first==0){
  Item* newItem=new Item();
  if (head_!=nullptr){
    head_->prev=newItem;
    newItem->next=head_;
  }
  head_=newItem;
  if(tail_==nullptr){
    tail_=head_;
  }
}
  
  head_->first--;
  head_->val[head_->first]=val;
  size_++;
}

void ULListStr::pop_back(){
  if (!tail_){
    return;
  }

  tail_->last--;
  size_--;

  if(tail_->first==tail_->last){
    Item* temp=tail_;
    tail_=tail_->prev;

    if (tail_){
      tail_->next=nullptr;
    }

    else{
      head_=nullptr;
    }

    delete temp;
  }
  
}

void ULListStr::pop_front(){
  if(!head_){
    return;
  }

  head_->first++;
  size_--;

  if (head_->first==head_->last){
    Item* temp=head_;
    head_=head_->next;

    if (head_){
      head_->prev=nullptr;
    }

    else{
      tail_=nullptr;
    }

    delete temp;
  }
}

string const & ULListStr::back() const{
  if(!tail_){
     throw out_of_range("empty list");
  }

  return tail_->val[tail_->last-1];
}

string const & ULListStr::front() const{
  if (!head_){
    throw out_of_range("empty list");
  }

  return head_->val[head_->first];
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