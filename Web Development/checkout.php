<?php
ob_start(); 
session_start();
require_once('config/connect.php');

if(!isset($_SESSION['customer']) & empty($_SESSION['customer'])){
	header('location:login.php');
}
include'inc/header.php';
include'inc/nav.php';
$uid=$_SESSION['customerid'];
$cart = $_SESSION['cart'];

if(isset($_POST) & !empty($_POST)){
	if($_POST['agree'] == true){
		$country=filter_var($_POST['country'], FILTER_SANITIZE_STRING);
		$first=filter_var($_POST['first'], FILTER_SANITIZE_STRING);
		$last=filter_var($_POST['last'], FILTER_SANITIZE_STRING);
		$company=filter_var($_POST['company'], FILTER_SANITIZE_STRING);
		$address1=filter_var($_POST['address1'], FILTER_SANITIZE_STRING);
		$address2=filter_var($_POST['address2'], FILTER_SANITIZE_STRING);
		$city=filter_var($_POST['city'], FILTER_SANITIZE_STRING);
		$state=filter_var($_POST['state'], FILTER_SANITIZE_STRING);
		$zip=filter_var($_POST['zip'], FILTER_SANITIZE_NUMBER_INT);
		$mobile=filter_var($_POST['mobile'], FILTER_SANITIZE_NUMBER_INT);
		$payment=filter_var($_POST['payment'], FILTER_SANITIZE_STRING);
		// echo"<pre>";
		// print_r($_POST);
	
		// echo"</pre>";
		$sql="SELECT * FROM user_meta WHERE uid='$uid' ";
		$res=mysqli_query($conn,$sql);
		$row=mysqli_fetch_assoc($res);
		$count=mysqli_num_rows($res);
		if($count == 1){
			// update user data
		 	$usql="UPDATE user_meta SET country='$country', first='$first', last='$last', company='$company', address1='$address1', address2='$address2', city='$city', state='$state', zip='$zip', mobile='$mobile' WHERE uid=$uid";
		 	$ures=mysqli_query($conn,$usql);
			if($ures){
				$total=0;
				foreach ($cart as $key => $value) {
					// echo "<br>".$key." : ".$value['quantity']."<br>";
					$ordsql="SELECT * FROM products where id =$key";
					$ordres=mysqli_query($conn,$ordsql);
					$ordrow=mysqli_fetch_assoc($ordres);
					$total=$total+($ordrow['price'] * $value['quantity']);
				}
				if($payment == "cod"){
					?><?php echo '<script>alert("Payment Successfully !")</script>'; ?><?php
					$iosql="INSERT INTO orders (uid,totalprice,orderstatus,paymentmode) VALUES('$uid','$total','Order Placed','$payment')";
					$iores=mysqli_query($conn,$iosql)or die(mysqli_error($conn));
					if($iores){
						// echo"order inserted and redirect to my account";
				 		$orderid=mysqli_insert_id($conn);
						foreach ($cart as $key => $value) {
							// echo "<br>".$key." : ".$value['quantity']."<br>";
							$ordsql="SELECT * FROM products where id =$key";
							$ordres=mysqli_query($conn,$ordsql);
							$ordrow=mysqli_fetch_assoc($ordres);
							$pid=$ordrow['id'];
							$productprice=$ordrow['price'];
							$pquantity=$value['quantity'];


							$orditmsql="INSERT INTO orderitems (pid,orderid,productprice,pquantity) VALUES('$pid','$orderid','$productprice','$pquantity')";
							$orditmres=mysqli_query($conn,$orditmsql)or die(mysqli_error($conn));
							// if($orditmres){
							// 	// echo"    order items inserted and redirect to my account";
							// }
						}
					}
					unset($_SESSION['cart']);
					header('location:my-account.php');
				}
				/*$iosql="INSERT INTO orders (uid,totalprice,orderstatus,paymentmode) VALUES('$uid','$total','Order Placed','$payment')";*/
				/*$iores=mysqli_query($conn,$iosql)or die(mysqli_error($conn));
				if($iores){
					// echo"order inserted and redirect to my account";
				 	$orderid=mysqli_insert_id($conn);
					foreach ($cart as $key => $value) {
						// echo "<br>".$key." : ".$value['quantity']."<br>";
						$ordsql="SELECT * FROM products where id =$key";
						$ordres=mysqli_query($conn,$ordsql);
						$ordrow=mysqli_fetch_assoc($ordres);
						$pid=$ordrow['id'];
						$productprice=$ordrow['price'];
						$pquantity=$value['quantity'];


						$orditmsql="INSERT INTO orderitems (pid,orderid,productprice,pquantity) VALUES('$pid','$orderid','$productprice','$pquantity')";
						$orditmres=mysqli_query($conn,$orditmsql)or die(mysqli_error($conn));
						// if($orditmres){
						// 	// echo"    order items inserted and redirect to my account";
						// }
					}
				}
				unset($_SESSION['cart']);
				header('location:my-account.php');*/
			} 
			// if($ures){
			// 	print_r($cart);
			// 	echo "do";
			// }
			// 	$total=0;
			// 	foreach ($cart as $key => $value) {
			// 	// echo "<br>".$key." : ".$value['quantity']."<br>";
			// 	$ordersql="SELECT * FROM products where id =$key";
			// 	$orderres=mysqli_query($conn,$ordersql);
			// 	$orderrow=mysqli_fetch_assoc($orderres);
			// 	echo $total=$total+($urow['price']*$value['quantity']);
			
			// }
			// echo $iosql="INSERT INTO orders (uid,totalprice,orderstatus,paymentmode) VALUES('$uid','$total','Order Placed','$payment')";
			// $ores=mysqli_query($conn,$iosql) or die(mysqli_error($conn));
			// 	if($ores){
			// 		echo"Order inserted into orders and orderitems ";
			// 		$orderid=mysqli_insert_id($conn);
			// 		foreach ($cart as $key => $value) {
			// 		// echo "<br>".$key." : ".$value['quantity']."<br>";
			// 		$ordersql="SELECT * FROM products where id =$key";
			// 		$orderres=mysqli_query($conn,$ordersql);
			// 		$orderrow=mysqli_fetch_assoc($orderres);
			// 		$pid=$orderrow['id'];
			// 		$productprice=$orderrow['price'];
			// 		$orditm="INSERT INTO orderitems(pid,orderid,productprice) VALUES('$pid','$orderid','$productprice')";
			// 		$orditmres=mysqli_query($conn,$orditm);
			// 		if($orditmres){
			// 			echo"order itm directly insert to my account";
			// 		}
			// 	}
		}else{
			// insert user data
			$isql="INSERT INTO user_meta(country,first,last,company,address1,address2,city,state,zip,mobile,uid)VALUES('$country','$first','$last','$company','$address1','$address2' ,'$city','$state','$zip','$mobile','$uid')";
			$ires=mysqli_query($conn,$isql);
			if($ires){
				$total=0;
				foreach ($cart as $key => $value) {
					// echo "<br>".$key." : ".$value['quantity']."<br>";
					$ordsql="SELECT * FROM products where id =$key";
					$ordres=mysqli_query($conn,$ordsql);
					$ordrow=mysqli_fetch_assoc($ordres);
					$total=$total+($ordrow['price'] * $value['quantity']);
				}
				$iosql="INSERT INTO orders (uid,totalprice,orderstatus,paymentmode) VALUES('$uid','$total','Order Placed','$payment')";
				$iores=mysqli_query($conn,$iosql)or die(mysqli_error($conn));
				if($iores){
					// echo"order inserted and redirect to my account";
					$orderid=mysqli_insert_id($conn);
					foreach ($cart as $key => $value) {
						// echo "<br>".$key." : ".$value['quantity']."<br>";
						$ordsql="SELECT * FROM products where id =$key";
						$ordres=mysqli_query($conn,$ordsql);
						$ordrow=mysqli_fetch_assoc($ordres);
						$pid=$ordrow['id'];
						$productprice=$ordrow['price'];
						$pquantity=$value['quantity'];


						$orditmsql="INSERT INTO orderitems (pid,orderid,productprice,pquantity) VALUES('$pid','$orderid','$productprice','$pquantity')";
						$orditmres=mysqli_query($conn,$orditmsql)or die(mysqli_error($conn));
						// if($orditmres){
						// 	// echo"    order items inserted and redirect to my account";
						// }
					}
				}
				unset($_SESSION['cart']);
				header('location:my-account.php');
			}
		}
	}else{
		?>
		<?php
			echo '<script>alert("Must tick the term and conditions !")</script>';
		?>
		<?php
	}
}
 ?>

	
	<div class="close-btn fa fa-times"></div>
	<?php
	$sql="SELECT * FROM user_meta WHERE uid='$uid' ";
	$res=mysqli_query($conn,$sql);
	$row=mysqli_fetch_assoc($res);

	?>
	
	<!-- SHOP CONTENT -->
	<section id="content">
		<div class="content-blog">
					<div class="page_header text-center">
						<h2 style="line-height:100px; font-size:60px; color:rgba(148, 9, 9, 0.958); font-family:italic;">Checkout</h2>
					</div>
<form action=""method="post">
<div class="container">
			<div class="row">
				<div class="col-md-6 col-md-offset-3">
					<div class="billing-details">
						
						<h3 class="uppercase">Billing Details</h3>
						
						<div class="space30"></div>
						
							<label class="">Country </label>
							<select class="form-control"name="country">
							<option value="Afghanistan">Afghanistan</option>
                            <option value="Armenia">Armenia</option>	
                            <option value="Azerbaijan">Azerbaijan</option>	
                            <option value="Bahrain">Bahrain</option>	
                            <option value="Bangladesh">Bangladesh</option>	
							<option value="Bhutan">Bhutan</option>
							<option value="Brunei">Brunei</option>
							<option value="Cambodia">Cambodia</option>
							<option value="China">China</option>
							<option value="East Timor">East Timor</option>
							<option value="Georgia">Georgia</option>
							<option value="Hong Kong">Hong Kong</option>
							<option value="India">India</option>
							<option value="Indonesia">Indonesia</option>
							<option value="Iran">Iran</option>
							<option value="Iraq">Iraq</option>
							<option value="Japan">Japan</option>
							<option value="Jordan">Jordan</option>
							<option value="Kazakhstan">Kazakhstan</option>
							<option value="Kuwait">Kuwait</option>
							<option value="Kyrgyzstan">Kyrgyzstan</option>
							<option value="Laos">Laos</option>
							<option value="Lebanon">Lebanon</option>
							<option value="Macau">Macau</option>
							<option value="Malaysia">Malaysia</option>
							<option value="Maldives">Maldives</option>
							<option value="Mongolia">Mongolia</option>
							<option value="Myanmar">Myanmar</option>
							<option value="Nepal">Nepal</option>
							<option value="North Korea">North Korea</option>
							<option value="Oman">Oman</option>
							<option value="Pakistan">Pakistan</option>
							<option value="Palestine">Palestine</option>
							<option value="Philippines">Philippines</option>
							<option value="Qatar">Qatar</option>
							<option value="Russia">Russia</option>
							<option value="Saudi Arabia">Saudi Arabia</option>
							<option value="Singapore">Singapore</option>
							<option value="South Korea">South Korea</option>
							<option value="Sri Lanka">Sri Lanka</option>
							<option value="Taiwan">Taiwan</option>
							<option value="Tajikistan">Tajikistan</option>
							<option value="Thailand">Thailand</option>
							<option value="Turkey">Turkey</option>
							<option value="Uzbekistan">Uzbekistan</option>
							<option value="Vietnam">Vietnam</option>
							<option value="Yemen">Yemen</option>

							</select>
							<div class="clearfix space20"></div>
							<div class="row">
								<div class="col-md-6">
									<label>First Name </label>
									<input class="form-control" name="first"placeholder="" value="<?php if(!empty($row['first'])){echo $row['first']; }?>" type="text"required>
								</div>
								<div class="col-md-6">
									<label>Last Name </label>
									<input class="form-control" name="last"placeholder="" value="<?php if(!empty($row['last'])){echo $row['last']; }?>" type="text"required>
								</div>
							</div>
							<div class="clearfix space20"></div>
							<label>Address </label>
							<input class="form-control" name="address1"placeholder="Street address" value="<?php if(!empty($row['address1'])){echo $row['address1']; }?>" type="text"required>
							<div class="clearfix space20"></div>
							<input class="form-control" name="address2"placeholder="Apartment, suite, unit etc. (optional)" value="<?php if(!empty($row['address2'])){echo $row['address2']; }?>" type="text"required>
							<div class="clearfix space20"></div>
							<div class="row">
								<div class="col-md-4">
									<label>Town / City </label>
									<input class="form-control" name="city"placeholder="Town / City" value="<?php if(!empty($row['city'])){echo $row['city']; }?>" type="text"required>
								</div>
								<div class="col-md-4">
									<label>State</label>
									<input class="form-control" value="<?php if(!empty($row['state'])){echo $row['state']; }?>" name="state"placeholder="State " type="text"required>
								</div>
								<div class="col-md-4">
									<label>Postcode </label>
									<input class="form-control" name="zip"placeholder="Postcode / Zip" value="<?php if(!empty($row['zip'])){echo $row['zip']; }?>" type="text"required>
								</div>
							</div>
							<div class="clearfix space20"></div>
							<label>Phone </label>
							<input class="form-control" id="billing_phone" name="mobile"placeholder="" value="<?php if(!empty($row['mobile'])){echo $row['mobile']; }?>" type="text"required>
						
					</div>
				</div>
				
			
			</div>
			
			<div class="space30"></div>
			<h4 class="heading">Cart Totals</h4>
			
			<table class="table table-bordered extra-padding">
				<tbody>
					<tr>
						<th>Subtotal</th>
						<td><span class="amount"><?php echo $total; ?></span></td>
					</tr>
					<tr>
						<th>Shipping</th>
						<td>
							Free Shipping				
						</td>
					</tr>
					<tr>
						<th>Order Total</th>
						<td><strong><span class="amount"><?php echo $total; ?></span></strong> </td>
					</tr>
				</tbody>
			</table>
			
			<div class="clearfix space30"></div>
			<h4 class="heading">Payment Method</h4>
			<div class="clearfix space20"></div>
			
			<div class="payment-method">
				<div class="row">
					
						<div class="col-md-4">
							<input name="payment" id="radio1" class="css-checkbox" name=""type="radio"value="cod"><span>Cash on Delivery</span>
							<div class="space20"></div>
							<p>Make your payment directly into our bank account. Please use your Order ID as the payment reference. Your order won't be shipped until the funds have cleared in our account.</p>
						</div>
								
				</div>
				<form action="payment.php" >
				<div class="space30"></div>
				
					<input name="agree" id="checkboxG2" class="css-checkbox"value="true" type="checkbox"name=""><span>I've read and accept the <a href="#">terms &amp; conditions</a></span>
				
				<div class="space30"></div>
				<input type="submit"class="button btn-lg"name="" value="Pay Now">
				
				

				</div>
		</div>		
</form>		
		</div>
	</section>
	

<?php include'inc/footer.php';?>