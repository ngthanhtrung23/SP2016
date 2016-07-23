[Video](https://www.youtube.com/watch?v=Vy1RAkkcp5k)

[Slide](https://docs.google.com/presentation/d/1fCuD76w6MP7V2F2QzCssbD1mB1ehz2_4f9_nrhOjC3I/edit#slide=id.g15ed0ae9f0_0_180)

# [problem:208018A]

Đề yêu cầu tìm phép đổi chỗ sao cho có ít nghịch thế nhất --> duyệt mọi phép đổi chỗ.

- Có $O(N^2)$ phép đổi chỗ
- Do đó với mỗi phép đổi chỗ cần xử lý trong $O(1)$.

Với mỗi phép đổi chỗ 2 phần tử $i$ và $j$, ta phân tích xem những cặp nghịch thế nào bị ảnh hưởng. Sau khi vẽ ra và xét các trường hợp, ta rút ra được các trường hợp:

- Trước khi đổi chỗ:
    - Các cặp $(u, v)$ mà $u = i$, $v \in [i, j]$
    - Các cặp $(u, v)$ mà $u \in [i, j]$, $v = j$.
- Sau khi đổi chỗ
    - Các cặp $(u, v)$ mà $u = j$, $v \in [i, j]$
    - Các cặp $(u, v)$ mà $u \in [i, j]$, $v = i$.

Để tính các giá trị trên, ta cần trả lời các câu hỏi dạng: Có bao nhiêu số trong đoạn $[l, r]$ có giá trị lớn hơn $x$.

Vẽ các điểm $(i, A(i))$ lên mặt phẳng:

![ ](http://i581.photobucket.com/albums/ss253/__RR__/Screenshot%20from%202016-07-23%20114736_zpseh7zoctf.png)

Ta thấy các cái cần tính là số điểm trong 1 hình chữ nhật. Từ đó dùng kĩ thuật kiểu mảng cộng dồn 2D là có thể giải quyết bài toán. Ví dụ $f(i, j)$ là số số từ 1 đến $i$, và có giá trị lớn hơn $j$.


[Code](http://ideone.com/nLlJMJ)


# [problem:208018B]

## N^4

Dùng kĩ thuật mảng cộng dồn, ta dễ dàng tính được tổng của 1 hình chữ nhật có 2 đỉnh đối nhau là $(i, j)$ và $(u, v)$

Khởi tạo mảng cộng dồn:

$S(i, j)$ = tổng các số trong hình chữ nhật có 2 đỉnh đối nhau là $(1, 1)$ và $(i, j)$.

--> $S(i, j) = S(i-1, j) + S(i, j-1) - S(i-1, j-1) + A(i, j)$ với $A(i, j)$ là số ở ô $(i, j)$.

--> tổng các số trong 1 hình chữ nhật có 2 đỉnh đối diện $(i, j)$ và $(u, v)$, nếu $i \le u$ và $j \le v$ là:

$S(u, v) - S(u, j-1) - S(i-1, v) + S(i-1, j-1)$.


Như vậy ta có thể tính tổng 1 hình chữ nhật bất kỳ trong $O(1)$. Từ đó ta có thuật toán $N^4$ rất đơn giản: Xét tất cả các hình chữ nhật con trong bảng, với mỗi hình kiểm tra tổng các phần tử bên trong nó có đủ $K$ hay không.


## N^3

1 hình chữ nhật được xác định bởi 4 biến: tọa độ của 2 đỉnh đối diện. $(i, j)$ và $(u, v)$. Thông thường cách tiếp cận các bài toán có nhiều biến chưa biết là ta duyệt 1 vài biến và tìm các biến còn lại trong thời gian đủ nhanh.

Ở đây ta duyệt 2 biến i và u. Nói cách khác là ta cố định cạnh trên và cạnh dưới của hình chữ nhật. Khi đó, mỗi cột luôn gồm các số từ hàng i đến hàng u. Nếu ta đặt

$x(j) = sum( A(i,j) + A(i+1, j) + ... + A(u, j) )$

thì bài toán trở thành bài toán 1 chiều: cho 1 dãy số $x$. Tìm l và r sao cho $r - l + 1$ nhỏ nhất và tổng các phần tử từ l đến r lớn hơn hoặc bằng $K$.

Để giải bài toán này, thì ta nhận thấy, khi r di chuyển sang phải, thì l cũng di chuyển sang phải, nên ta có thể thu được thuật toán $O(N)$ như sau:

```cpp
int l = 1;
for (int r = 1; r <= N; r++) {
    // chạy l theo r chừng nào vẫn có thể chạy được
    while (l < r && sum(l+1, r) <= K) ++l; // hàm sum(l, r) trả lại tổng các số l --> r trong O(1)
                                           // dùng kĩ thuật mảng cộng dồn
    if (sum(l, r) >= K) {
        // cập nhật kết quả theo [l, r]
    }
}
```

[Code](http://ideone.com/n2wdOC)


# [problem:208018C]

## Tư tưởng

Nhận xét: các bài toán vòng tròn (ví dụ như bài này là xoay xâu theo vòng tròn) thường rất khó giải quyết. Kĩ năng thông thường là ta tìm các đưa các bài đó về đường thẳng rồi giải quyết. Có 2 cách thông thường:

- Cắt vòng tròn tại 1 điểm
- Nhân đôi

Ở bài này ta sẽ nhân đôi xâu lên.

Xét xâu $S' = AHYANGYIAHYANGYI$. Ta thấy mỗi cách xoay vòng tròn xâu $S$ tương ứng với 1 substring của xâu $S'$ độ dài $LS$.

Như vậy, bài toán trở thành: với mỗi đoạn con dài $N$ của xâu $S'$, đếm số cách để biến nó thành xâu $T$.

Với mỗi đoạn con dài $N$ của xâu $S'$, có 3 trường hợp:

- Nó và xâu $T$ không khác nhau --> Có $N$ cách thay đổi
- Nó và xâu $T$ khác nhau ở đúng 1 vị trí --> Có 1 cách thay đổi
- Nó và xâu $T$ khác nhau ở ít nhất 2 vị trí --> Không có cách thay đổi nào cả.

Như vậy, việc quan trọng nhất là đếm số vị trí khác nhau của 2 xâu.

Cụ thể, với mỗi đoạn $[l, r]$ trên xâu $S'$, ta sẽ cần biết:

- Đoạn kết thúc ở $r$ của xâu $S'$ khớp với bao nhiêu kí tự cuối của xâu $T$
- Đoạn bắt đầu ở $l$ của xâu $S'$ khớp với bao nhiêu kí tự đầu của xâu $T$.

Từ 2 thông tin đó ta có thể xác định được đoạn $[l, r]$ thuộc trường hợp nào trong 3 trường hợp nói trên.


## Hash

[Hash tutorial](http://vnoi.info/library/121/4964/)

Sử dụng hash, ta dễ dàng so sánh 2 xâu con có bằng nhau hay không trong $O(1)$. Như vậy, bằng chặt nhị phân, ta có thể tính được các thông tin trên trong $O(logN)$.


## KMP

Khi áp dụng thuật toán KMP với xâu $S'$ và $T$, ở mỗi vị trí trên xâu $S'$ ta biết được nó khớp với nhiều nhất bao nhiêu kí tự đầu của xâu $T$. Ví dụ:

```
S = ABCABC
T = ABC
```

Thì ta biết ở vị trí 5 trên xâu $S$ khớp được với 2 vị trí đầu của xâu $T$, vị trí 6 của xâu $S$ khớp với 3 vị trí đầu của xâu $T$. Cái này bị ngược với cái mà ta cần tính --> `:@)`. Cách giải quyết xem trong code kỳ diệu phía dưới.


## Z-function

Định nghĩa hàm Z giống hệt như cái mình cần tính ở bài này --> nếu biết Z chỉ cần chép vào là AC.

Code:

- [KMP](http://ideone.com/aHOzb7)
- [Hash](http://ideone.com/9Hz5Zy)
- [Z-Function](http://ideone.com/FjPB7k)


# [problem:208018D]

## Thuật toán:

Tìm chu trình euler. Sau khi có chu trình euler, bài toán đưa về vòng tròn.

## Vòng tròn

Xét vòng tròn. Mỗi cạnh trên vòng tròn có 1 trọng số. Tìm vị trí xuất phát để đi vòng quanh vòng tròn, mà không lúc nào tổng nhỏ hơn 0.

