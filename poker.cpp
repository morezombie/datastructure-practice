//20171120庞华冲

//定义牌的数据结构
typedef struct poker{

int value;//牌面
int mark;//花色
poker* next;//指向下一节点

}


class PlayPoker {

public:
//获取同花顺
poker* GetTriple();
//其他方法
vector<poker*> GetPokerList();
poker* SetPokerList();
~PlayPoker();
PlayPoker():pokers(NULL){}

private:
//保存牌的链表
poker* pokers;
//检查是否同花顺
bool isTriple(poker*);
}


//获取同花顺
vector<poker*> PlayPoker::GetTriple() {


poker* tmp_list;//保存一个3元素队列
poker* ptr = pokers;//用作遍历的指针
vector<poker*> result;//保存所有的同花顺

//遍历链表

while(ptr) {

//读入一牌，插入到3元素队列
if(tmp_list==NULL) {
tmp_list=ptr;
}else if(tmp_list->next==NULL)
tmp_list->next=ptr;
}else if(tmp_list->next->next==NULL)
tmp_list->next->next=ptr;
}
//如果3元素队列不足，则继续
if(!tmp->next || !tmp->next->next) continue;
//检查3元素队列是否同花顺
bool res=isTriple(tmp_list);
//是则将该3元素队列放入容器，清空3元素队列，继续遍历
if(res) {
result.push_back(tmp_list);//深复制
delete tmp_list->next->next;
delete tmp_list->next;
delete tmp_list;
}
//否则将3元素的第一元素出队，继续遍历
else{
poker* ptr_tmp = tmp_list;
tmp_list=ptr_tmp->next;
delete ptr_tmp;
}
//将牌链表的指针向前一步
ptr=ptr->next;

}

//将所有收集到的同花顺返回
return result;


}


//检查是否同花顺
bool PlayPoker::isTriple(poker* list) {

poker sort[3];


sort[0]=list;
sort[1]=list->next;
sort[2]=list->next->next;

//花色相同
if(sort[0].mark==sort[1].mark && sort[0].mark==sort[2].mark) {
//TODO考察是否连续
return true;
}
//花色不同
else {
return false;
}

}
