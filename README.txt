File này được viết với độ rộng nửa màn hình máy 15.6'

Với mỗi file INP, dữ liệu sẽ được đọc theo trong file code
Dòng đầu tiên luôn luôn là số đỉnh của đồ thị.
Những dòng tiếp theo sẽ là một bộ số của các đỉnh.
Với mỗi đỉnh sẽ không cần nhập tên đỉnh mà bắt đầu nhập vào
dữ liệu tại đỉnh đó luôn. Ví dụ như: Giá trị của đỉnh hay còn
gọi là h(u), các đỉnh kề với nó, giá trị của các cạnh kề hay
còn gọi là k(u,v) và các giá trị này thì có thể có hoặc không.
Để kết thúc việc nhập dữ liệu cho mỗi đỉnh thì sẽ đọc vào 0.
Với những bạn không rõ là đồ thị vô hướng hay có hướng thì
ta sẽ dựa vào việc trong tập cạnh kề của 2 đỉnh đó có nhau 
hay không. Ví dụ nếu là vô hướng thì nếu trong bộ dữ liệu của
đỉnh 1 sẽ có đỉnh 2 thì trong bộ dữ liệu của đỉnh 2 sẽ có 
đỉnh 1. Còn giả như là có hướng thì nếu trong bộ dữ liệu của
đỉnh 1 có đỉnh 2 thì trong bộ dữ liệu của đỉnh 2 sẽ không có
đỉnh 1.
Và ta cũng giả thiết rằng, toàn bộ đồ thị mẫu chỉ là đơn đồ 
thị có hướng liên thông yếu hoặc đơn đồ thị vô hướng liên 
thông, không tồn tại nút khuyên.

Chi tiết hơn, ta có thể thấy:
Từ file 1 đến file 4, dòng đầu là số đỉnh.
Những dòng tiếp theo xét từ đỉnh 1 tới đỉnh n, mỗi dòng lưu
các đỉnh kề với nó, kết thúc bởi số 0.
Các file sau, dòng đầu là số đỉnh.
Những dòng tiếp theo xét từ đỉnh 1 tới đỉnh n.
Dòng đầu của mỗi đỉnh là giá trị tại đỉnh đó. 
Các dòng sau là đỉnh kề với nó và giá trị của cạnh nối.
Kết thúc bởi số 0.

Để hiểu rõ hơn đồ thị dùng trong code vui lòng xem minh họa. 
Ưu tiên file inp rồi đến ảnh png rồi đến jpg.