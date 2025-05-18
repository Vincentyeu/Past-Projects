
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

	$first=filter_var($_POST['first'], FILTER_SANITIZE_STRING);
	$last=filter_var($_POST['last'], FILTER_SANITIZE_STRING);
	$address1=filter_var($_POST['address1'], FILTER_SANITIZE_STRING);
	$address2=filter_var($_POST['address2'], FILTER_SANITIZE_STRING);
	$city=filter_var($_POST['city'], FILTER_SANITIZE_STRING);
	$zip=filter_var($_POST['zip'], FILTER_SANITIZE_NUMBER_INT);
	$mobile=filter_var($_POST['mobile'], FILTER_SANITIZE_NUMBER_INT);
	// echo"<pre>";
	// print_r($_POST);
	
	// echo"</pre>";
	// $sql="SELECT * FROM user_meta WHERE uid='$uid' ";
	// $res=mysqli_query($conn,$sql);
	// $row=mysqli_fetch_assoc($res);
	// $count=mysqli_num_rows($res);
	// if($count == 1){
		// update user data
		 $usql="UPDATE user_meta SET 'first='$first', last='$last', address1='$address1', address2='$address2', city='$city', zip='$zip', mobile='$mobile' WHERE uid=$uid";
		 $ures=mysqli_query($conn,$usql);
		if($ures){
			
		 
		
	}
// }
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
						<h2 style="line-height:100px; font-size:60px; color:rgba(148, 9, 9, 0.958); font-family:italic;">Update Address</h2>
						<p>Get the best kit for smooth shave</p>
					</div>
<form action=""method="post">
<div class="container">
			<div class="row">
				<div class="col-md-6 col-md-offset-3">
					<div class="billing-details">
						
						<h3 class="uppercase">Update My Address</h3>
						
						<div class="space30"></div>
						
							<label class="">City </label>
							<select class="form-control"name="city">
								<option value="City">Select City</option>
								<option value="JB">Johor Bahru</option>
								<option value="GT">George Town</option>
								<option value="KL">Kuala Lumpur</option>
								<option value="KC">Kuching</option>
								<option value="KK">Kota Kinabalu</option>
								<option value="SA">Shah Alam</option>
								<option value="PJ">Petaling Jaya</option>
								<option value="IH">Ipoh</option>
								<option value="IP">Iskandar Puteri</option>
								<option value="MC">Malacca City</option>
								<option value="AS">Alor Setar</option>
								<option value="SB">Seremban</option>
								<option value="KN">Kuantan</option>
								<option value="KB">Kota Bahru</option>
								<option value="KT">Kuala Terengganu</option>
								<option value="LB">Labuan</option>
								<option value="PT">Putrajaya</option>
								
							</select>


							<div class="clearfix space20"></div>
							<div class="row">
								<div class="col-md-6">
									<label>First Name </label>
									<input class="form-control" name="first"placeholder="" value="<?php if(!empty($row['first'])){echo $row['first']; }?>" type="text">
								</div>
								<div class="col-md-6">
									<label>Last Name </label>
									<input class="form-control" name="last"placeholder="" value="<?php if(!empty($row['last'])){echo $row['last']; }?>" type="text">
								</div>
							</div>
							<div class="clearfix space20"></div>
							<label>Address 1</label>
							<input class="form-control" name="address1"placeholder="Street address" value="<?php if(!empty($row['address1'])){echo $row['address1']; }?>" type="text">
							<div class="clearfix space20"></div>
							<input class="form-control" name="address2"placeholder="Apartment, suite, unit etc. (optional)" value="<?php if(!empty($row['address2'])){echo $row['address2']; }?>" type="text">
							<div class="clearfix space20"></div>
							<div class="row">
								<div class="col-md-4">
									<label>Postcode </label>
									<input class="form-control" name="zip"placeholder="Postcode / Zip" value="<?php if(!empty($row['zip'])){echo $row['zip']; }?>" type="text">
								</div>
							</div>
							<div class="clearfix space20"></div>
							<label>Phone </label>
							<input class="form-control" id="billing_phone" name="mobile"placeholder="" value="<?php if(!empty($row['mobile'])){echo $row['mobile']; }?>" type="text">
							
							<div class="space30"></div>
							<input type="submit"class="button btn-lg" value="UPDATE ADDRESS">
					</div>
				</div>
				
			
			</div>
		</div>		
</form>		
		</div>
	</section>
	

<?php include'inc/footer.php';?>
