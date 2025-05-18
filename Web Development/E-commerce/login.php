<?php 
session_start();
include'inc/header.php';
require_once('config/connect.php');
include'inc/nav.php';
 ?>	
	
	<div class="close-btn fa fa-times"></div>

	
	<!-- SHOP CONTENT -->
	<section id="content">
		<div class="content-blog">
			<div class="container">
				<div class="row">
					<div class="page_header text-center">
						<h2 style="line-height:100px; font-size:60px; color:rgba(148, 9, 9, 0.958); font-family:italic;">Shop - Account</h2>
						<p>Tagline Here</p>
					</div>
					<div class="loginform">
						<div class="row shop-login">
							<div class="loginform">
								<div class="box-content">
									<h3 class="heading text-center">Login Now</h3>
										<div class="clearfix space40"></div>
										<?php
											if(isset($_GET['message']) ){ ?>
												<div class="alert alert-danger"><?php echo "Invalied email or password !"; ?></div>
											<?php } ?>
										<form class="logregform"method="post" action="loginprocess.php">
											<div class="row">
												<div class="form-group">
													<div class="loginform">
														<label>E-mail Address</label>
														<input type="text" name="email"value="" class="form-control">
													</div>
												</div>
											</div>
											<div class="clearfix space20"></div>
											<div class="row">
												<div class="form-group">
													<div class="loginform">
														<!-- <a class="pull-right" href="#">(Lost Password?)</a> -->
														<label>Password</label>
														<input type="password" name="password" value="" class="form-control">
													</div>
												</div>
											</div>
											<div class="clearfix space20"></div>
											<div class="row">
												<div class="loginform">
													<!-- <span class="remember-box checkbox">
													<label for="rememberme">
													<input type="checkbox" id="rememberme" name="rememberme">Remember Me
													</label>
													</span> -->
												</div>
												<div class="loginform">
													<button type="submit" class="button btn-md pull-right">Login</button>
												</div>
											</div>
										</form>
										<a href="register.php">Don't have an account?</a>
								</div>
							</div>
				
						</div>
					</div>
				</div>
			</div>
		</div>
	</section>
	
<?php include'inc/footer.php';?>


