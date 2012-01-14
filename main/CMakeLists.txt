CMAKE_MINIMUM_REQUIRED (VERSION 2.6) 
PROJECT (urlsort)

SET(CMAKE_C_FLAGS "-std=c99")

SET(urlsort_SRCS
	urlsort_main.c
)

ADD_EXECUTABLE(urlsort ${urlsort_SRCS})




