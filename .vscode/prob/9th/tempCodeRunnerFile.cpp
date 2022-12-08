if (first == ptr_snode && last == ptr_snode) { // SNode가 유일한 노드일 때
		first = NULL;
		last = NULL;
	}
	else if (first == ptr_snode) { // remove first
		ptr_snode->next->prev = NULL;
		first = ptr_snode->next;
	}
	else if (last == ptr_snode) { // remove last
		ptr_snode->prev->next = NULL;
		last = ptr_snode->prev;
	}
	else { // in the middle
		ptr_snode->next->prev = ptr_snode->prev;
		ptr_snode->prev->next = ptr_snode->next;
	}