#include <iostream>
#include "Item.h"       
#include "Weapon.h"     
#include "Potion.h"     
#include "Inventory.h"  

using namespace std;

// 메인에서 모든 기능 테스트
int main()
{
    cout << "==== [1] Inventory<Item> 기본 기능 ====\n";
    Inventory<Item> inv(3);

    // 자동 확장(AddItem)
    inv.AddItem(Item("사과", 10));
    inv.AddItem(Item("바나나", 5));
    inv.AddItem(Item("수박", 30));
    inv.AddItem(Item("복숭아", 15)); // capacity=3이므로 여기서 2배 확장

    cout << "\n[정렬 전]\n";
    inv.PrintAllItems();

    // 가격순 정렬 (Inventory<Item>에서만 호출)
    cout << "\n[가격 오름차순 정렬]\n";
    inv.SortItems();     // 내부에서 std::sort(..., CompareItemsByPrice) 호출
    inv.PrintAllItems();

    // Resize 테스트 (축소 => 뒤 요소 잘림)
    cout << "\n[Resize: 4 -> 2]\n";
    inv.Resize(2);
    inv.PrintAllItems();

    // 다시 확장
    cout << "\n[Resize: 2 -> 5]\n";
    inv.Resize(5);
    inv.AddItem(Item("체리", 25));
    inv.AddItem(Item("포도", 12));
    inv.PrintAllItems();

    // RemoveLastItem
    cout << "\n[RemoveLastItem]\n";
    inv.RemoveLastItem();
    inv.PrintAllItems();

    // 복사 생성자(깊은 복사)
    cout << "\n==== [2] 복사 생성자(깊은 복사) ====\n";
    Inventory<Item> copyInv = inv;  // 깊은 복사
    cout << "[원본] "; inv.PrintAllItems();
    cout << "[복사본] "; copyInv.PrintAllItems();

    // Assign(대입 역할)
    cout << "\n==== [3] Assign (덮어쓰기) ====\n";
    Inventory<Item> otherInv(1);
    otherInv.AddItem(Item("임시", 999));
    cout << "[대입 전 otherInv]\n";
    otherInv.PrintAllItems();

    otherInv.Assign(inv);
    cout << "[Assign 후 otherInv]\n";
    otherInv.PrintAllItems();


    cout << "\n[원본에 새 아이템 추가 후 영향 확인]\n";
    inv.AddItem(Item("망고", 28));
    cout << "원본 inv:\n"; inv.PrintAllItems();
    cout << "복사본 copyInv:\n"; copyInv.PrintAllItems();
    cout << "대입본 otherInv:\n"; otherInv.PrintAllItems();

    cout << "\n==== [4] Weapon / Potion 상속 아이템 데모 ====\n";

    Inventory<Weapon> wInv(2);
    wInv.AddItem(Weapon("철검", 100, 15));
    wInv.AddItem(Weapon("활", 120, 10));
    wInv.AddItem(Weapon("도끼", 90, 20)); // 자동 확장
    cout << "\n[무기 목록]\n";
    wInv.PrintAllItems();

    Inventory<Potion> pInv(2);
    pInv.AddItem(Potion("HP 포션", 30, 50));
    pInv.AddItem(Potion("MP 포션", 40, 30));
    cout << "\n[포션 목록]\n";
    pInv.PrintAllItems();



    cout << "\n==== 모든 테스트 종료 ====\n";
    return 0;
}
