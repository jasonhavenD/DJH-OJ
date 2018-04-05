package tree;

import java.util.Stack;


// ���������� 
public class BinTree {
	protected BTNode root;

	public BinTree(BTNode root) {
		this.root = root;
	}

	public BTNode getRoot() {
		return root;
	}

	
	//�����л������
	public ListNode EntryNodeOfLoop(ListNode pHead)
    {
         if(pHead == null || pHead.next == null)
            return null;
        ListNode p1 = pHead;
        ListNode p2 = pHead;
        while(p2 != null && p2.next != null ){
            p1 = p1.next;
            p2 = p2.next.next;
            if(p1 == p2){
                p2 = pHead;
                while(p1 != p2){
                    p1 = p1.next;
                    p2 = p2.next;
                }
                if(p1 == p2)
                    return p1;
            }
        }
        return null;
    }
	
	// ��ʼ�������������
	public static BTNode init() {
		BTNode a = new BTNode('A');
		BTNode b = new BTNode('B', null, a);
		BTNode c = new BTNode('C');
		BTNode d = new BTNode('D', b, c);
		BTNode e = new BTNode('E');
		BTNode f = new BTNode('F', e, null);
		BTNode g = new BTNode('G', null, f);
		BTNode h = new BTNode('H', d, g);
		return h; // �����
	}

	// ���ʽڵ�
	public static void visit(BTNode p) {
		System.out.print(p.getKey() + " ");
	}

	// �ݹ�ʵ��ǰ�����
	protected static void preorder(BTNode p) {
		if (p != null) {
			visit(p);
			preorder(p.getLeft());
			preorder(p.getRight());
		}
	}

	// �ݹ�ʵ���������
	protected static void inorder(BTNode p) {
		if (p != null) {
			inorder(p.getLeft());
			visit(p);
			inorder(p.getRight());
		}
	}

	// �ݹ�ʵ�ֺ������
	protected static void postorder(BTNode p) {
		if (p != null) {
			postorder(p.getLeft());
			postorder(p.getRight());
			visit(p);
		}
	}

	// �ǵݹ�ʵ��ǰ�����
	protected static void iterativePreorder(BTNode p) {
		Stack<BTNode> stack = new Stack<BTNode>();
		if (p != null) {
			stack.push(p);
			while (!stack.empty()) {
				p = stack.pop();
				visit(p);
				if (p.getRight() != null)
					stack.push(p.getRight());
				if (p.getLeft() != null)
					stack.push(p.getLeft());
			}
		}
	}

	// �ǵݹ�ʵ�ֺ������
	protected static void iterativePostorder(BTNode p) {
		BTNode q = p;
		Stack<BTNode> stack = new Stack<BTNode>();
		while (p != null) {
			// ��������ջ
			for (; p.getLeft() != null; p = p.getLeft())
				stack.push(p);
			// ��ǰ��������ӽ������ӽ���Ѿ����
			while (p != null && (p.getRight() == null || p.getRight() == q)) {
				visit(p);
				q = p; // ��¼��һ����������
				if (stack.empty())
					return;
				p = stack.pop();
			}
			// �������ӽ��
			stack.push(p);
			p = p.getRight();
		}
	}

	// �ǵݹ�ʵ���������
	protected static void iterativeInorder(BTNode p) {
		Stack<BTNode> stack = new Stack<BTNode>();
		while (p != null) {
			while (p != null) {
				if (p.getRight() != null)
					stack.push(p.getRight()); // ��ǰ������ӽ����ջ
				stack.push(p); // ��ǰ�����ջ
				p = p.getLeft();
			}
			p = stack.pop();
			while (!stack.empty() && p.getRight() == null) {
				visit(p);
				p = stack.pop();
			}
			visit(p);
			if (!stack.empty())
				p = stack.pop();
			else
				p = null;
		}
	}

	public static void main(String[] args) {
		BinTree tree = new BinTree(init());

		System.out.print(" �ݹ�ʵ��ǰ�����:");
		preorder(tree.getRoot());
		System.out.println("\n");

		System.out.print(" �ݹ�ʵ���������:");
		inorder(tree.getRoot());
		System.out.println("\n");

		System.out.print(" �ݹ�ʵ�ֺ������:");
		postorder(tree.getRoot());
		System.out.println("\n");

		System.out.print(" �ǵݹ�ʵ��ǰ�����:");
		iterativePreorder(tree.getRoot());
		System.out.println("\n");

		System.out.print(" �ǵݹ�ʵ���������:");
		iterativeInorder(tree.getRoot());
		System.out.println("\n");

		System.out.print(" �ǵݹ�ʵ�ֺ������:");
		iterativePostorder(tree.getRoot());
		System.out.println("\n");

	}
}



/**
 * @author Mrdai
 * ���������
 */
class BTNode {
	private char key; // ����
	private BTNode left, right; // �����ӽ��

	public BTNode(char key) {
		this(key, null, null);
	}

	public BTNode(char key, BTNode left, BTNode right) {
		this.key = key;
		this.left = left;
		this.right = right;
	}

	public char getKey() {
		return key;
	}

	public void setKey(char key) {
		this.key = key;
	}

	public BTNode getLeft() {
		return left;
	}

	public void setLeft(BTNode left) {
		this.left = left;
	}

	public BTNode getRight() {
		return right;
	}

	public void setRight(BTNode right) {
		this.right = right;
	}

}
class ListNode {
    int val;
    ListNode next = null;

    ListNode(int val) {
        this.val = val;
    }
}