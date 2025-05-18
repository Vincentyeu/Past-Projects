<?php 
session_start();
include'inc/header.php';
require_once('config/connect.php');
include'inc/nav.php';
 ?>	
<!DOCTYPE html>
<html>
  <head>
    <title>About Us - Online Gift Store</title>
  </head>
  <body>
  </br></br></br></br></br></br>
    <h1 style="line-height:100px; font-size:60px; color:rgba(148, 9, 9, 0.958); font-family:italic;">ABOUT US</h1>
	</br></br></br>
      <h2>Our Story</h2>
      <p>Our online gift store was founded in 2020 with the goal of providing unique and thoughtful gifts for all occasions. We source products from local artisans and small businesses to bring you a carefully curated selection of gifts that you won't find anywhere else.</p>
	</br>
      <h2>Our Mission</h2>
      <p>Our mission is to provide high-quality, unique gifts that bring joy to people's lives. We strive to offer excellent customer service and make gift-giving a stress-free and enjoyable experience.</p>
      <br/>
	  <ul>
        <li>- "I was impressed with the variety of unique and high-quality products available on the Online Gift Store website."</li>
        <li>- "I bought a personalized photo album for my parents' anniversary and they loved it! The craftsmanship was top-notch."</li>
      </ul>
	</br>
      <h2>Product Reviews</h2>
      <p>We are proud of the quality of our products and the positive feedback we receive from our customers. Read some of our product reviews below:</p>
	</br>
	  <h2>Customer Reviews</h2>
    <p>We value the feedback of our customers and are always striving to improve. Read some of our customer reviews below:</p>
	</br>
	<ul>
      <li>- "The customer service team at Online Gift Store was extremely helpful in finding the perfect gift for my mother."</li>
      <li>- "I had a great experience shopping on the Online Gift Store website. The checkout process was easy and my order was delivered on time."</li>
      <li>- "I appreciate the wide selection of unique and high-quality products offered by Online Gift Store."</li>
    </ul>
	</br>
    <h2>Upcoming Events and Promotions</h2>
    <p>We regularly host events and offer promotions to our customers. Check out what's coming up:</p>
	</br>
	<ul>
    <li>- Summer Sale - Save 20% on select products from June 1st to August 31st.</li>
    <li>- Virtual Craft Fair - Join us on Zoom on July 10th to meet local artisans and shop their unique products.</li>
    <li>- Customer Appreciation Day - Stop by our physical store on September 1st for free refreshments and special discounts.</li>
  </ul>
    </br></br>
    <?php include'inc/footer.php';?>

<style>
h1{
  font-family: bebas-neue, sans-serif;
	color:#000;
	text-transform:uppercase;
	font-size:80px;
	font-weight:400;
}

h2 {
  background-color: gainsboro ; /* Add background color */
  color: black;
  padding: 3px;
  margin-left: 180px;
  margin-right: 180px;
  font-size: 30px;
  margin-bottom: 10px;
  font-family: bebas-neue, sans-serif;
}

p{
	font-size: 17px;
	color: black;
	margin-left: 180px;
	margin-right: 180px;
  font-family: bebas-neue, sans-serif;
}

ul{
	font-size: 14px;
	margin-left: 200px;
	margin-right: 180px;
	color: black;
  font-family: bebas-neue, sans-serif;
}
</style>


