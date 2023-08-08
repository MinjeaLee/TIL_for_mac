type GetActionOptions struct {
ActionID       uint
Type           ActionType
TeamID         uint
ChallengeID    uint
type GetActionOptions struct {
func (db *actions) Get(ctx context.Context, opts GetActionOptions) ([]*Action, error) {
var actions []*Action
return actions, db.WithContext(ctx).Model(&Action{}).Where(&Action{
Model:          gorm.Model{ID: opts.ActionID},
Type:           opts.Type,
TeamID:         opts.TeamID,
ChallengeID:    opts.ChallengeID,
func (db *actions) Get(ctx context.Context, opts GetActionOptions) ([]*Action, e
}).Find(&actions).Error
}