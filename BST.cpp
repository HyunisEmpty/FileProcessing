#include <iostream>
#include <stack>

template <class _Tp> class Node;
template <class _Tp> class BST;


template <class _Tp> // Node 클래스 템플릿 선언
class Node {
	public: // Member types
		typedef _Tp					__key_type;             // Key type 별칭 
		typedef Node<__key_type>*	__node_pointer_type;    // Node 포인터 별칭
	
	public: // Member variables
		__key_type			__key_;                         // Key type key 생성
		__node_pointer_type	__left_;                        // Node type 포인터 생성1       
		__node_pointer_type	__right_;                       // Node type 포인터 생성2
	
	public: // Constructor -> 생성자 선언 영역
		Node(): __key_(__key_type()), __left_(nullptr), __right_(nullptr) {}                // 기본 생성자 키를 타입의 기본값으로 초기화
		Node(const __key_type& key): __key_(key), __left_(nullptr), __right_(nullptr) {}    // 값을 받아 키를 초기화 하는 생성자

	/*
	* 아래는 inorder traversal을 대체할 수 있는 operator<< 입니다.
	* 반드시 아래의 함수를 사용해야할 필요는 없습니다.
	*/
	friend std::ostream& operator<<(std::ostream& os, const __node_pointer_type& np) {
		if (np == nullptr){
			return os;
		}

		os << "<";
		os << np->__left_;
		os << " ";
		os << np->__key_;
		os << " ";
		std::cout << np->__right_;
		os << ">";
		
		return os;
	}
};

/*
* 아래 함수들의 설계 방식은 Tree와 Node의 구동부를 구현하기 위해 추천드리는 설계 방식입니다.
* 반드시 아래의 설계 방식을 따라야 하는 것은 아닙니다.
*/

template <class _NodePtr>   
unsigned __height(_NodePtr __x) {   // 트리의 높이를 반환하는 함수 -> Node 포인터 타입 매개변수, 반환 타입은 0 이상의 정수
	// write your own code here
}

template <class _NodePtr>           // 트리의 크기를 반환하는 함수 -> Node 포인터 타입 매개변수, 반환 타입은 0 이상의 정수
unsigned __size(_NodePtr __x) {
	// write your own code here
}

/*
* 아래 함수는 minNode와 동일한 역할을 하는 함수입니다.
* 매개 변수 타입과 반환 타입을 참조 타입으로 수정하셔도 무방합니다.
*/
template <class _NodePtr>
_NodePtr __tree_min(_NodePtr __x) { // 트리의 최소값을 반환하는 함수 -> Node 포인터 타입 매개변수, 반환 타입은 Node 포인터 타입
	// write your own code here
}

/*
* 아래 함수는 maxNode와 동일한 역할을 하는 함수입니다.
* 매개 변수 타입과 반환 타입을 참조 타입으로 수정하셔도 무방합니다.
*/
template <class _NodePtr>
_NodePtr __tree_max(_NodePtr& __x) { // 트리의 최대값을 반환하는 함수 -> Node 포인터 타입 매개변수, 반환 타입은 Node 포인터 타입
	// 해당 함수가 호출 되는 시점은 트리에 항상 노드가 있는 상황을 가정
	_NodePtr p = __x;

	while(p->__right_ != nullptr){
		p = p->__right_;
	}

	return p;
}

/*
* PDF에 명시되어있는 출력 형식에 유의하세요.
* ❗️잘못된 출력 형식은 0점 처리됩니다.❗️
*/
template <class _NodePtr>
void __inorder(_NodePtr __x) {      // 트리의 중위 순회 출력 함수 -> Node 포인터 타입 매개변수, 반환 타입은 없음(void)
	// write your own code here
}

template <class _NodePtr, class _Tp>
_NodePtr __serachBST(_NodePtr& __root, const _Tp& key) { // 트리에서 key를 검색하는 함수 -> Node 포인터 타입 매개변수와 key 타입 매개변수, 반환 타입은 Node 포인터 타입
	_NodePtr p = __root;	// 타겟 노드 포인터

	// 키가 일치 하지 않는 경우 p가 nullptr이 아닌경우
	while( p != nullptr && p->__key_ != key ){
		if (key < p->__key_){
			p = p->__left_;
		}
		else{
			p = p->__right_;
		}
	}

	return p;
}

template <class _NodePtr, class _Tp>
_NodePtr __serachParent(_NodePtr& __root, const _Tp& key) { // 트리에서 key를 검색하는 함수 -> Node 포인터 타입 매개변수와 key 타입 매개변수, 반환 타입은 Node 포인터 타입
	_NodePtr q = nullptr;	// 타겟 노드의 부모 노드 포인터
	_NodePtr p = __root;	// 타겟 노드 포인터

	// 키가 일치 하지 않는 경우 p가 nullptr이 아닌경우
	while( p != nullptr && p->__key_ != key ){
		q = p; 
		if (key < p->__key_){
			p = p->__left_;
		}
		else{
			p = p->__right_;
		}
	}

	return q;
}

template <class _NodePtr, class _Tp>
std::pair<_NodePtr, bool> __insertBST(_NodePtr& __root, const _Tp& key) {	// 반환타입이 pair인데 이는 서로다른 두개의 값을 묶어서 한번에 반환하는 구조체 템플릿이다. 
	_NodePtr q = nullptr; // 부모 노드를 가리키는 포인터
    _NodePtr p = __root;  // 현재 노드를 가리키는 포인터 초기 값은 rootnode를 가리키도록 설정

    // 비어있는 트리가 아니라면 내가 삽입할 key노드가 존재하는지 확인한다. 
    while (p != nullptr){
        if (key == p->__key_){  // 삽입할 키가 이미 존재 한다면 키와 false를 반환
            return std::pair<_NodePtr, bool>(p, false); 
        }
        q = p; 
        if (key < p->__key_){
            p = p->__left_;
        }
        else {
            p = p->__right_;
        }
    }

    // 힙 영역에 메모리를 동적 할당하여서 Node 객체 생성, new를 통해 할당된 메모리 주소 반환( 함수 종료 후에도 존재하게 하기 위함 )
    _NodePtr newNode = new Node<_Tp>;
    newNode->__key_ = key; 
    newNode->__left_ = nullptr;
    newNode->__right_ = nullptr;

    // Tree가 비어 있는지를 __root 가 nullptr과 같은지를 통해서 확인 (BST 생성자 기본값이 nullptr임)
    if (__root == nullptr){ 
        __root = newNode;
    } 
    else if(newNode->__key_ < q->__key_){   // 삽입할 값이 부모 노드의 키값보다 작은 경우 
        q->__left_ = newNode;
    }
    else{                                   // 삽입할 값이 부모 노드의 키값보다 큰 경우
        q->__right_ = newNode;
    }

    return std::pair<_NodePtr, bool>(newNode, true); 
}

/*
* Root node가 삭제되는 경우를 고려하여 매개 변수 "__root" 를 참조 타입으로 받도록 설계하였습니다.
* "__root = 대체될 노드"로 BST class의 멤버 변수 __root_ 값을 변경할 수 있습니다.
* 현재 로직에서 존재하지 않는 key를 erase하려고 할 때, nullptr을 반환해야 정상 작동하도록 설계되어 있습니다.
*/
template <class _NodePtr, class _Tp>
_NodePtr __eraseBST(_NodePtr& __root, const _Tp& key) {		// key노드를 삭제했다면 삭제한 노드의 포인터를 반환해야 한다. 없다면 null
	_NodePtr p = __serachBST(__root, key);		// 삭제할 노드 포인터 
	_NodePtr q = __serachParent(__root, key);	// 삭제할 노드의 부모 노드 포인터 
	_NodePtr r = nullptr;						// 왼쪽 서브트리 최댓값을 저장할 노드

	if (p == nullptr){			// 1.tree에 삭제할 노드가 없는 경우
		return nullptr;
	}
	else if (q == nullptr){		// 2.tree에서 root를 삭제하는 경우
		if (p -> __left_ == nullptr && p->__right_ == nullptr){		// 2-1.삭제할 노드의 차수가 0인 경우
			__root = nullptr;
		}
		else if(p->__left_ == nullptr || p->__right_ == nullptr){	// 2-2.삭제할 노드의 차수가 1인 경우
			if(p->__left_ != nullptr){	// 자식이 왼쪽에 있는 경우 
				__root = p->__left_;				// 왼쪽 노드가 루트노드가 된다. 
			}
			else{						// 자식이 오른쪽에 있는 경우 
				__root = p->__right_;			// 오른쪽 노드가 루트 노드가 된다.
			}
		}
		else{														// 2-3.삭제할 노드의 차수가 2인 경우
			r = __tree_max(p->__left_);	// 왼쪽 서브트리의 최대값 찾기 
			p->__key_ = r->__key_;					// 최댓값의 키값을 루트 노드에 삽입
			return __eraseBST(p->__left_,r->__key_);
		}	
		return p;
	}
	else{						// 3.tree에서 root가 아닌 node를 삭제하는 경우
		if(p->__left_ == nullptr && p->__right_ == nullptr){		// 3-1.삭제할 노드의 차수가 0인 경우
			if(q->__left_ == p){						
				q->__left_ = nullptr;
			}else{
				q->__right_ = nullptr;
			}
		}
		else if(p->__left_ == nullptr || p->__right_ == nullptr){	// 3-2.삭제할 노드의 차수가 1인 경우 
			if (p->__left_ != nullptr){			// 왼쪽 서브 트리가 있는 경우
				if(q->__left_ == p){					
					q->__left_ = p->__left_;
				}else{
					q->__right_ = p->__left_;
				}
			}else{								// 오른쪽 서브 트리가 있는 경우
				if(q->__left_ == p){					
					q->__left_ = p->__right_;
				}else{
					q->__right_ = p->__right_;
				}
			}
		}
		else{														// 3-3.삭제할 노드의 차수가 1인 경우 
			r = __tree_max(p->__left_);
			p->__key_ = r->__key_;
			return __eraseBST(p->__left_,r->__key_);
		}
		return p;
	}
}

// Dangling pointer를 방지하기 위해 __x를 참조 타입으로 받도록 설계하였습니다.
template <class _NodePtr>
void __clear(_NodePtr& __x) {
	// write your own code here
}

// 아래는 반드시 사용해야하는 BST 클래스입니다.
template <class _Tp>
class BST {
	public: // 멤버 타입의 별칭을 지정
		typedef _Tp						key_type;
		typedef std::size_t				size_type;
		typedef Node<key_type>*			pointer;
		typedef const Node<key_type>*	const_pointer;
	
	private: // Member variables
		pointer	__root_;
	
	public: // Constructor
		BST(): __root_(nullptr) {}  // 기본 생성자, __root_를 nullptr로 초기화

	public: // Capacity
		size_type height() const {
			// use __height or write your own code here
			return __height(__root_);
		}

		size_type size() const {
			// use __size or write your own code here
			return __size(__root_);
		}
	
	public: // Lookup
		void inorder() const {
			// use __inorder or write your own code here
			__inorder(__root_);
			std::cout << std::endl;
		}
		
	public: // Modifier
		std::pair<const_pointer, bool> insert(const key_type& key) {
			// use __insertBST or write your own code here
			return __insertBST(__root_, key);
		}

		const_pointer erase(const key_type& key) {
			// use __eraseBST or write your own code here
			// 삭제를 하는 경우 삭제한 노드의 포인터를 반환
			pointer __r = __eraseBST(__root_, key);

			// Client still needs to destruct/deallocate it
			// Or memory leak will occur
			delete __r;		// 삭제한 노드를 메모리 상에서 제거

			return __r; 
		}

		void clear() {
			// use __clear or write your own code here
			__clear(__root_);
		}
	
	/*
	* 아래는 inorder traversal을 대체할 수 있는 operator<< 입니다.
	* 반드시 아래의 함수를 사용해야할 필요는 없습니다.
	*/
	// tree 객체가 호출 된고, 내부에서 node객체를 해당 연산으로 한번 더 호출
	friend std::ostream& operator<<(std::ostream& os, const BST& tree) {
		os << tree.__root_;
		return os;
	}
};

/*
* 아래는 추천드리는 main 함수의 예시입니다.
* 반드시 아래의 main 함수를 사용해야할 필요는 없습니다.
* ❗️새로 구현하실 경우, 출력 형식에 주의하세요.❗️
*/
int main(int argc, char **argv) {
	BST<int>	tree;           // BST 객체 생성
	char		command;        // command 문자 변수 선언
	int			key;            // key 정수 변수 선언 

	while (std::cin >> command >> key) {
		switch ((int)command) {
			case (int)'i':
				if (tree.insert(key).second == false) {
					std::cerr << "i " << key << ": The key already exists" << std::endl;
					continue;
				}
				break;
			case (int)'d':
				if (tree.erase(key) == nullptr) {	// null인 경우 -> 삭제할 값이 존재 하지 않는다. 
					std::cerr << "d " << key << ": The key does not exist" << std::endl;
					continue;
				}
				break;
			default:
				std::cerr << "Invalid command: " << command << std::endl;
				return (1);
				break;
		}
		std::cout << tree << std::endl;
	}

	// 프로그램 종료 전, 메모리 누수가 발생하지 않도록 할당받은 메모리를 반드시 해제해야 합니다.
	tree.clear();

	return (0);
}