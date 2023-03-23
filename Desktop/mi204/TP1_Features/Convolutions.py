import numpy as np
import cv2

from matplotlib import pyplot as plt

#Lecture image en niveau de gris et conversion en float64
img=np.float64(cv2.imread('../Image_Pairs/FlowerGarden2.png',0))
(h,w) = img.shape
print("Dimension de l'image :",h,"lignes x",w,"colonnes")
  """
  val = 5*img[y, x] - img[y-1, x] - img[y, x-1] - img[y+1, x] - img[y, x+1]    #laplacien
  img2[y,x] = min(max(val,0),255)
  """
#Méthode directe
t1 = cv2.getTickCount()
img2 = cv2.copyMakeBorder(img,0,0,0,0,cv2.BORDER_REPLICATE)
for y in range(1,h-1):
  for x in range(1,w-1):
   
    val_x = -img[y-1, x+1] + img[y+1, x+1] -img[y-1, x] + img[y+1, x] -img[y-1, x-1] + img[y+1, x-1]    #gradient Ix
    val_y = -img[y-1, x+1] + img[y-1, x-1] -img[y, x+1] + img[y, x-1] -img[y+1, x+1] + img[y+1, x-1]    #gradient Iy
    val = np.sqrt(val_x*val_x + val_y*val_y)   #norme de I = sqrt(I_x² + I_y²)
    img2[y,x] = min(abs(val),255)
    
t2 = cv2.getTickCount()
time = (t2 - t1)/ cv2.getTickFrequency()
print("Méthode directe :",time,"s")
xxx = abs(-10)
print(xxx)
cv2.imshow('Norme de I',img2.astype(np.uint8))
#Convention OpenCV : une image de type entier est interprétée dans {0,...,255}
cv2.waitKey(5000)


plt.subplot(121)
plt.imshow(img2,cmap = 'gray')
plt.title('Convolution - Méthode Directe')

#Méthode filter2D
t1 = cv2.getTickCount()
kernel = np.array([[0, -1, 0],[-1, 5, -1],[0, -1, 0]])
img3 = cv2.filter2D(img,-1,kernel)
t2 = cv2.getTickCount()
time = (t2 - t1)/ cv2.getTickFrequency()
print("Méthode filter2D :",time,"s")

cv2.imshow('Avec filter2D',img3/255.0)
#Convention OpenCV : une image de type flottant est interprétée dans [0,1]
cv2.waitKey(0)

plt.subplot(122)
plt.imshow(img3,cmap = 'gray',vmin = 0.0,vmax = 255.0)
#Convention Matplotlib : par défaut, normalise l'histogramme !
plt.title('Convolution - filter2D')

plt.show()

"""
img4 = img3-img2
cv2.imshow('diff',img4.astype(np.uint8))
#Convention OpenCV : une image de type entier est interprétée dans {0,...,255}
cv2.waitKey(0)
"""