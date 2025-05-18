<?php 
session_start();
include'inc/header.php';
require_once('config/connect.php');
include'inc/nav.php';
 ?>	

<section id="content">
		<div class="content-blog">
			<div class="container">
				<div class="row">
					<div class="page_header text-center">
						<h2 style="line-height:100px; font-size:60px; color:rgba(148, 9, 9, 0.958); font-family:italic;">Shop - Account</h2>
						<p>Tagline Here</p>
					</div>
                    <div class="registerform">
					    <div class="box-content">
						    <h3 class="heading text-center">Register An Account</h3>
						    <div class="clearfix space40"></div>
						    <form class="logregform"method="post">
							    <div>
								    <?php
									    session_start();
									    require_once('config/connect.php');
									    if(isset($_POST) &!empty($_POST)){
										    $email=$_POST['email'];
										    $pass=$_POST['password'];
										    $cpass=$_POST['passwordagain'];
										    $select = mysqli_query($conn, "SELECT * FROM `user` WHERE email='$email' AND password='$pass'");
									    }
								    ?>
							    </div>
							    <div>
								    <?php
									    if(mysqli_num_rows($select) > 0)
									    {
										    $message[] = 'User already exist';
									    }
									    else
									    {
										    if($pass != $cpass)
									    	{
											    $message[] = 'Confirm password not matched !';
										    }
										    else
										    {
											    $insert = mysqli_query($conn, "INSERT INTO `user`(email, password) VALUES('$email', '$pass')");
							
											    if($insert)
											    {
												    $success[] = 'Register Successfully !';
											    }
                                                
										    }
									    }
								    ?>
							    </div>
							    <div>
								    <?php
                    				    if(isset($message))
                    				    {
                        				    foreach($message as $message)
                        				    {
                            				    ?><div class="alert alert-danger"><?php echo $message ?></div><?php
                        				    }
                    				    }
										else if(isset($success))
										{
											foreach($success as $success)
                        				    {
                            				    ?><div class="alert alert-success"><?php echo $success ?></div><?php
                        				    }
										}
                
                				    ?>
							    </div>
							    <div class="row">
								    <div class="form-group">
									    <div class="registerform">
										    <label>E-mail Address</label>
										    <input type="email" name="email"value="" class="form-control">
									    </div>
								    </div>
							    </div>
							    <div class="clearfix space20"></div>
							    <div class="row">
								    <div class="form-group">
									    <div class="registerform">
										    <label>Password</label>
										    <input type="password" name="password"value="" class="form-control">
									    </div>
									    <div class="registerform">
										    <label>Confirm Password</label>
										    <input type="password" name="passwordagain"value="" class="form-control">
									    </div>
								    </div>
							    </div>
							    <div class="row">
								    <div class="registerform">
									    <div class="space20"></div>
									    <button type="submit" class="button btn-md pull-right">Register</button>
								    </div>
							    </div>
						    </form>
                            <a href="login.php">Already have an account?</a>
					    </div>
				    </div>
                </div>
		    </div>
	    </div>
</section>

<?php include'inc/footer.php';?>
