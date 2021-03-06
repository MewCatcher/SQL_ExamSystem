/**
 * Name: TableAdmin.h
 * Author: MewCatcher
 * Date: 2014/05/09
 * Description: This class get the info from daatabase, and manage the info on this client
 **/

#ifndef _TABLEADMIN_H_
#define _TABLEADMIN_H_

typedef struct {
	char Name[ 256 ];
	bool canManageAdmin, canManageStudent, canSetProblem, canSetPaper, canSetExam, canDeleteGrade, canEditGrade;
} StructAdmin;

class TableAdmin
{
public:
	TableAdmin( );
	~TableAdmin( );

	bool Init( SQLHDBC hdbc_loc, string Name, string Password ); // This design is for safety
	void Delete( int line, SQLHDBC hdbc_loc );
	void Add( StructAdmin StrAdmin, ODBCManagement& ODBC, SQLHDBC hdbc_loc );
	void Edit( int line, StructAdmin StrAdmin, SQLHDBC hdbc_loc );


	string get_UserName( ) const;
	int get_AdminId( ) const;
	bool get_AdminType( ) const; // true - SU; false - Admin
	bool get_canManageAdmin( ) const;
	bool get_canManageStudent( ) const;
	bool get_canSetProblem( ) const;
	bool get_canSetPaper( ) const;
	bool get_canSetExam( ) const;
	bool get_canDeleteGrade( ) const;
	bool get_canEditGrade( ) const;
	bool JudgePassword( string OldHash ) const; // true - match

	bool FetchAdminList( ODBCManagement& ODBC, SQLHDBC hdbc_loc ); // Using ODBCM
	bool SetNewPassword( SQLHDBC hdbc_loc, string OldHash, string NewHash );
	int get_SA_count( ) const;
	StructAdmin get_SA( int line ) const;

private:
	bool hasInit;
	int AdminId;
	char AdminName[ 256 ];
	char PasswordHash[ 256 ];
	bool AdminType;
	bool canManageAdmin, canManageStudent, canSetProblem, canSetPaper, canSetExam, canDeleteGrade, canEditGrade;

	StructAdmin *SA;
	int SA_count;
};

#endif
