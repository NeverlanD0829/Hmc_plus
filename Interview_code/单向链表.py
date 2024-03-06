"""
    链表的基本操作，包括节点的添加和链表的展示。可以根据需要扩展这个链表，添加其他操作，如删除节点、插入节点等。
    Node 类:Node 类表示链表中的节点，每个节点包含一个值（value）和一个指向下一个节点的引用（next）。
            在节点初始化时，通过构造函数 __init__ 设置节点的值和初始的 next 引用为 None。
LinkedList 类:LinkedList 类是链表的主要类，包含一个头节点（head）。
            __init__ 方法初始化链表，开始时链表为空，head 被设置为 None。
            append 方法用于在链表末尾添加新的节点。
            display 方法用于打印链表中的所有节点值。
append 方法：当链表为空时，直接将新节点设置为头节点。否则，遍历链表找到最后一个节点，然后将新节点追加到最后一个节点的 next 引用上。
display 方法：从头节点开始遍历链表，打印每个节点的值，直到最后一个节点为止。
            使用 end=" -> " 来在打印时使用箭头连接节点值。最后打印 "None" 表示链表结束。
示例：
            创建一个 LinkedList 对象 my_linked_list。
            使用 append 方法向链表添加值为 1、2 和 3 的节点。
            使用 display 方法显示链表内容。
"""
class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, value):
        new_node = Node(value)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    def display(self):
        current_node = self.head
        while current_node:
            print(current_node.value, end=" -> ")
            current_node = current_node.next
        print("None")

# 示例
my_linked_list = LinkedList()
my_linked_list.append(1)
my_linked_list.append(2)
my_linked_list.append(3)
my_linked_list.display()
