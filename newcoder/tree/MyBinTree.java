package tree;

import java.util.Stack;

public class MyBinTree {
	private MyBinNode root;

	public MyBinNode getRoot() {
		return root;
	}

	/**
	 * <pre>
	 *           A
	 *     B          C
	 *  D     E            F
	 * </pre>
	 */
	public void init() {
		root = new MyBinNode('a', null, null);
		MyBinNode bBinNode = new MyBinNode('b', null, null);
		MyBinNode cBinNode = new MyBinNode('c', null, null);
		MyBinNode dBinNode = new MyBinNode('d', null, null);
		MyBinNode eBinNode = new MyBinNode('e', null, null);
		MyBinNode fBinNode = new MyBinNode('f', null, null);
		root.left = bBinNode;
		root.right = cBinNode;
		bBinNode.left = dBinNode;
		bBinNode.right = eBinNode;
		cBinNode.right = fBinNode;
	}

	public void visit(MyBinNode subTree) {
		System.out.println("data:" + subTree.data);
	}

	public void preOrder(MyBinNode subNode) {
		if (subNode != null) {
			visit(subNode);
			preOrder(subNode.left);
			preOrder(subNode.right);
		}
	}

	public void midOrder(MyBinNode subNode) {
		if (subNode != null) {
			midOrder(subNode.left);
			visit(subNode);
			midOrder(subNode.right);
		}
	}

	public void afterOrder(MyBinNode subNode) {
		if (subNode != null) {
			afterOrder(subNode.left);
			afterOrder(subNode.right);
			visit(subNode);
		}
	}

	// �ǵݹ�ǰ��
	public void noRecPreOrder(MyBinNode p) {
		Stack<MyBinNode> stack = new Stack<>();
		if (p != null) {
			stack.push(p);
			while (!stack.isEmpty()) {
				MyBinNode node = stack.pop();
				visit(node);
				if (node.right != null) {
					stack.push(node.right);
				}
				if (node.left != null) {
					stack.push(node.left);
				}
			}
		}
	}

	// �ǵݹ�����
	public void noRecMidOrder(MyBinNode p) {
		Stack<MyBinNode> stack = new Stack<MyBinNode>();
		while (p != null) {
			while (p != null) {
				if (p.right != null)
					stack.push(p.right); // ��ǰ������ӽ����ջ
				stack.push(p); // ��ǰ�����ջ
				p = p.left;
			}
			p = stack.pop();
			while (!stack.empty() && p.right == null) {
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

	// �ǵݹ����
	public void noRecAfterOrder(MyBinNode p) {
		MyBinNode q = p;
		Stack<MyBinNode> stack = new Stack<MyBinNode>();
		while (p != null) {
			// ��������ջ
			for (; p.left != null; p = p.left)
				stack.push(p);
			// ��ǰ��������ӽ������ӽ���Ѿ����
			while (p != null && (p.right == null || p.right == q)) {
				visit(p);
				q = p; // ��¼��һ����������
				if (stack.empty())
					return;
				p = stack.pop();
			}
			// �������ӽ��
			stack.push(p);
			p = p.right;
		}
	}

	public static void main(String[] args) {
		MyBinTree myBinTree = new MyBinTree();
		myBinTree.init();
		System.out.println("ǰ�����");
		myBinTree.preOrder(myBinTree.getRoot());
		System.out.println("�������");
		myBinTree.midOrder(myBinTree.getRoot());
		System.out.println("�������");
		myBinTree.afterOrder(myBinTree.getRoot());
		System.out.println("�ǵݹ�ǰ��");
		myBinTree.noRecPreOrder(myBinTree.root);
		System.out.println("�ǵݹ����");
		myBinTree.noRecAfterOrder(myBinTree.root);
	}

}

class MyBinNode {
	public char data;
	public MyBinNode left, right;

	public MyBinNode(char data, MyBinNode left, MyBinNode right) {
		super();
		this.data = data;
		this.left = left;
		this.right = right;
	}

}
