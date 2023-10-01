import numpy as np
import matplotlib.pyplot as plt
import time

def read_1d_data(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
        data = [complex(float(line.split()[0]), float(line.split()[1])) for line in lines]
    return np.array(data)

start = time.time()

# 1D 데이터 읽기
data_1d = read_1d_data('./mrimage1d.txt')

# 1D 데이터를 2D 형태로 재구성
reshaped_data = data_1d.reshape(256, 256)

# 데이터의 크기 확인
# print(reshaped_data.shape)

# 2D 푸리에 변환
# f_transformed = np.fft.fft2(reshaped_data)
# f_shifted = np.fft.fftshift(f_transformed)

# 크기 이미지를 표시

# magnitude_spectrum = 20 * np.log(np.abs(f_shifted))
magnitude_spectrum = 20 * np.log(np.abs(reshaped_data))

# print(magnitude_spectrum)
# plt.imshow(magnitude_spectrum, cmap='gray')
plt.imshow(magnitude_spectrum, cmap='gray')
plt.title('Magnitude Spectrum')
plt.colorbar()
end = time.time()
print(end - start)
# 이미지 저장
plt.savefig('magnitude_spectrum.png', dpi=300, bbox_inches='tight')
plt.show()
