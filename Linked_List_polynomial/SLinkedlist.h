
#ifndef SLinkedlist_h
#define Slinkedlist_h
template <typename E> class SLinkedList;	// forward declaration to be used when declaring SNode

template <typename E>
class SNode {					// singly linked list node
private:
	E elem;					// linked list element value
	SNode<E> *next;				// next item in the list
	friend class SLinkedList<E>;		// provide SLinkedList access
};

template <typename E>
class SLinkedList {				// a singly linked list
public:
	// Iterator is a nested class within SNodeList<E>
	class Iterator {				// an iterator for the list
	public:
		E& get() {		// reference to the element
			return v->elem;
		}
		E& operator*() {		// reference to the element
			return v->elem;
		}
		bool operator==(const Iterator& p) const {	// compare positions
			return v == p.v;
		}
		bool operator!=(const Iterator& p) const {
			return v != p.v;
		}
		Iterator& operator++() {		// move to next position
			v = v->next; return *this;
		}
		friend class SNodeList;			// give NodeList access
	private:
		SNode<E>* v;					// pointer to the node
		Iterator(SNode<E>* u) {		// constructor from SNode*
			v = u;
		}
	};

public:
	SLinkedList();				// empty list constructor
	~SLinkedList();				// destructor
	bool empty() const;			// is list empty?
	E& front();					// return front element
	void addFront(const E& e);		// add to front of list
	void removeFront();			// remove front item list
	int size() const;					// list size
	Iterator begin() const {		// beginning position is first item
		return Iterator(head);
	}
	Iterator end() const {		// end position is just beyond last
		return Iterator(NULL);
	}
	double evaluate(const double& x) const;
private:
	SNode<E>* head;				// head of the list
	int     n;							// number of items
};

template <typename E>
SLinkedList<E>::SLinkedList()			// constructor
	: head(NULL), n(0) { }

template <typename E>
bool SLinkedList<E>::empty() const		// is list empty?
{
	return head == NULL; // can also use return (n == 0);
}

template <typename E>
E& SLinkedList<E>::front() 		// return front element
{
	if (empty()) throw length_error("empty list");
	return head->elem;
}

template <typename E>
SLinkedList<E>::~SLinkedList()			// destructor
{
	while (!empty()) removeFront();
}

template <typename E>
void SLinkedList<E>::addFront(const E& e) {	// add to front of list
	SNode<E>* v = new SNode<E>;		// create new node
	v->elem = e;				// store data
	v->next = head;				// head now follows v
	head = v;				// v is now the head
	n++;
}

template <typename E>
void SLinkedList<E>::removeFront() {		// remove front item
	if (empty()) throw length_error("empty list");
	SNode<E>* old = head;			// save current head
	head = old->next;			// skip over old head
	delete old;				// delete the old head
	n--;
}
template <typename E>
int SLinkedList<E>::size() const {				// list size
	return n;
}
template<typename E>
double SLinkedList<E>::evaluate(const double& x) const

{
	double total = 0.0;
	SNode<E>* node = head;
	for (node; node != NULL; node = node->next)
	{
		total += (node->elem.getCoeff()) * (pow(x, node->elem.getOrder()));
	}
	return total;
}

#endif
