import numpy as np
import cv2

from matplotlib import pyplot as plt

#Lecture image en niveau de gris et conversion en float64
img=np.float64(cv2.imread('../Image_Pairs/Graffiti0.png',cv2.IMREAD_GRAYSCALE))
(h,w) = img.shape
print("Dimension de l'image :",h,"lignes x",w,"colonnes")
print("Type de l'image :",img.dtype)

#Début du calcul
t1 = cv2.getTickCount()
Theta = cv2.copyMakeBorder(img,0,0,0,0,cv2.BORDER_REPLICATE)
# Mettre ici le calcul de la fonction d'intérêt de Harris
kernel_x = np.array([[-1,1]])
Ix = cv2.filter2D(img,-1,kernel_x)
kernel_y = np.array([[-1],[1]])
Iy = cv2.filter2D(img,-1,kernel_y)
IxIx = np.square(Ix)
IyIy = np.square(Iy)
IxIy = Ix*Iy

kernel_1 = np.ones((3,3))
img1 = cv2.filter2D(IxIx,-1,kernel_1)
img2 = cv2.filter2D(IyIy,-1,kernel_1)
img3 = cv2.filter2D(IxIy,-1,kernel_1)
alpha = 0.04
Theta = img1*img2 - np.square(img3) - alpha*(img1 + img2)*(img1 + img2)
cv2.imshow("theta",Theta.astype(np.uint8))
cv2.waitKey(0)

"""""
# detect the corners with appropriate values as input parameters
gray_img = cv2.cvtColor(Theta, cv2.COLOR_BGR2GRAY)

# modify the data type setting to 32-bit floating point
gray_img = np.float32(gray_img)
corners_img = cv2.cornerHarris(gray_img, 3, 3, alpha)
cv2.imshow("corners_img",corners_img.astype(np.uint8))
cv2.waitKey(0)
"""
#
# Calcul des maxima locaux et seuillage
Theta_maxloc = cv2.copyMakeBorder(Theta,0,0,0,0,cv2.BORDER_REPLICATE)
d_maxloc = 3
seuil_relatif = 0.01
se = np.ones((d_maxloc,d_maxloc),np.uint8)
Theta_dil = cv2.dilate(Theta,se)
#Suppression des non-maxima-locaux
Theta_maxloc[Theta < Theta_dil] = 0.0
#On néglige également les valeurs trop faibles
Theta_maxloc[Theta < seuil_relatif*Theta.max()] = 0.0
t2 = cv2.getTickCount()
time = (t2 - t1)/ cv2.getTickFrequency()
print("Mon calcul des points de Harris :",time,"s")
print("Nombre de cycles par pixel :",(t2 - t1)/(h*w),"cpp")

plt.subplot(131)
plt.imshow(img,cmap = 'gray')
plt.title('Image originale')

plt.subplot(132)
plt.imshow(Theta,cmap = 'gray')
plt.title('Fonction de Harris')

se_croix = np.uint8([[1, 0, 0, 0, 1],
[0, 1, 0, 1, 0],[0, 0, 1, 0, 0],
[0, 1, 0, 1, 0],[1, 0, 0, 0, 1]])
Theta_ml_dil = cv2.dilate(Theta_maxloc,se_croix)
#Relecture image pour affichage couleur
Img_pts=cv2.imread('../Image_Pairs/Graffiti0.png',cv2.IMREAD_COLOR)
(h,w,c) = Img_pts.shape
print("Dimension de l'image :",h,"lignes x",w,"colonnes x",c,"canaux")
print("Type de l'image :",Img_pts.dtype)
#On affiche les points (croix) en rouge
Img_pts[Theta_ml_dil > 0] = [255,0,0]
plt.subplot(133)
plt.imshow(Img_pts)
plt.title('Points de Harris')

plt.show()
