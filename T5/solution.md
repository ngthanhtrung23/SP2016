# [problem:208180A]

## Tư tưởng

Interval Tree với 2 thao tác:

- Update(l, r, val): Gán tất cả đoạn [l, r] bằng val
- Get(i): Tìm giá trị tại điểm i

Bài này là Interval Tree khá cơ bản (cần lazy update). Giới hạn tương đối to để dụ các bạn làm rời rạc hóa. Tuy nhiên rời rạc hóa sẽ bị sai trong trường hợp sau:

```
3
1 20
20 30
1 10
```

Ở đây nếu rời rạc hóa về chỉ cần quan tâm các điểm 1, 10, 20, 30 thì sẽ sai. Hiện tại mình cũng không nghĩ ra cách nào đúng để giải quyết vấn đề này :)). (Lúc ở nhà nghĩ là với [l, r] thêm điểm l, r, l+1, r+1 là được nên đặt ML = 256MB, về sau mới nghĩ ra là nó vẫn sai)


# [problem:208180B]

Hướng đi thông thường là quy hoạch động theo kiểu $f(i, j, x)$, là nếu chỉ xét người từ $i$ đến $j$, thì thằng $x$ có vô địch được không. Tuy nhiên làm kiểu này độ phức tạp rất lớn và bộ nhớ cũng lớn.

Ta nhận thấy chiều $x$ không quan trọng, nói cách khác, ta sửa lại hàm $f(i, j)$ là có tồn tại cách chơi, để khi chơi hết đoạn $i$ đến $j$, thì còn lại cả $i$ và $j$.

Từ đó thu được công thức quy hoạch động $N^3$ rất đơn giản:

$f(i, j) = true$ nếu tồn tại $k$ mà $f(i, k) = f(k, j) = 1$ và $A(i,k) = 1 || A(j,k) = 1$.

Chú ý mối liên hệ giữa công thức mới $f(i, j)$ với công thức cũ $f(i, j, k)$. Ở đây $f(i, j)$ thể hiện là trong đoạn i - j còn cả 2 đầu i và j còn sống. Còn trong công thức $f(i, j, k)$ thể hiện trong đoạn i - j chỉ còn k còn sống.

Sau khi tính được $f(i, j)$, để xem i có thể còn sống sót đến cuối không, ta chỉ cần xem $f(i, i)$. Chú ý đây là cách xử lý trên hình tròn thông thường: cắt vòng tròn ở điểm i.


# [problem:208180C]

## 1D

Trước tiên, ta tìm cách giải bài toán trên 1D.

Trên 1D, mỗi mèo có tọa độ $xi$ và các mèo có thể di chuyển sang trái hoặc phải.

Tọa độ khá nhỏ nên ta có thể duyệt tất cả các điểm gặp gỡ, mỗi điểm gặp gỡ thì ta xét lần lượt từng mèo, tính số cách để mèo đấy đến điểm gặp nhau.

Có khoảng $O(max tọa độ + M)$ vị trí gặp nhau. Với mỗi vị trí gặp nhau, với mỗi mèo, ta tính số cách để mèo di chuyển từ vị trí X đến vị trí gặp nhau Y.

Đặt $l$ là số lần mèo di chuyển sang trái
Đặt $r$ là số lần mèo di chuyển sang phải

--> $l + r = M$
và $X - l + r = Y$

Từ đó tính được $l$ và $r$. Dùng tổ hợp tính đc số cách di chuyển là $C(M, l)$
