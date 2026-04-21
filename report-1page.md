# Report 1 Page – FIT4012 Lab 2

## 1. Mục tiêu
Tìm hiểu và cài đặt hai thuật toán mã hóa cổ điển là Caesar Cipher và Rail Fence Cipher, bao gồm cả chức năng mã hóa và giải mã, đồng thời kiểm tra dữ liệu đầu vào và làm việc với file.

## 2. Cách làm
- Hoàn thiện Caesar Cipher cho chữ thường, dấu cách và giải mã.
- Hoàn thiện Rail Fence Cipher cho giải mã, giữ dấu cách, kiểm tra đầu vào và đọc file.
- Chạy thử trên nhiều test case.

## 3. Kết quả chính
### 3.1 Caesar Cipher
| Input | Key | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 3 | L ORYH BRX | Dịch mỗi ký tự +3 |
| hello world | 5 | mjqqt btwqi | Hoạt động đúng với chữ thường |
| LORYH BRX | 3 | I LOVE YOU | Giải mã chính xác |

### 3.2 Rail Fence Cipher
| Input | Rails | Ciphertext / Plaintext | Nhận xét |
|---|---:|---|---|
| I LOVE YOU | 2 | ILVYU OEO  | Sắp xếp zigzag 2 hàng |
| I LOVE YOU | 4 | IOU LV YE O | Zigzag nhiều hàng hơn |
| IOEOLVYU | 2 | ILOVEYOU | Giải mã đúng |

### 3.3 Input validation / file input
- Trường hợp đầu vào không hợp lệ:
  Ví dụ: "HELLO123" → bị từ chối do chứa ký tự không phải chữ cái.
- Kết quả đọc từ `data/input.txt`:
  Đọc thành công nội dung file và thực hiện mã hóa Rail Fence bình thường.

## 4. Kết luận
Qua bài lab, em hiểu rõ cách hoạt động của Caesar Cipher (dịch ký tự theo bảng chữ cái) và Rail Fence Cipher (sắp xếp zigzag). Khó khăn lớn nhất là xử lý giải mã Rail Fence do phải tái tạo đúng cấu trúc ban đầu. Bài lab giúp em hiểu rõ hơn về xử lý chuỗi trong C++ và cách kiểm tra dữ liệu đầu vào.
