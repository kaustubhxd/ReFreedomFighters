"""specs_s408.py - batch 408: ZFFHERO::ClassFrameUpdate (0x58d000), the root of the hero's frame update.
Lifted callees that need much engine state are hooked (logged); small pure ones run as exe code (see docs)."""
import math
from pilot import S
import fu_kit as K


def _cstr(e, p, n=64):
    b = e.rbytes(p, n)
    return b.split(b'\0')[0]


def _wild(ee, a):
    """stand-in for striwcmp on these patterns ("X*"): 0 when the string starts with X, any case."""
    pat = _cstr(ee, ee.reg('edx')).rstrip(b'*').lower()
    return 0 if _cstr(ee, ee.reg('ecx')).lower().startswith(pat) else 1


def _root(c):
    r = c.rng
    e = c.emu
    now = r.randint(0x1000, 1 << 22)
    rb = lambda p=0.5: K.bool8(c, p)

    # ---- items, actors, objects
    def item_obj(name):
        tpl = K.rnd(c, 0x10)
        e.w32(tpl + 4, e.cstr(name) if name is not None else 0)
        it = K.obj(c, 0x40, {0x2f4: K.fn(c, 'item.GetItemOwner', 0, ret=lambda ee, a: owner[0]),
                             0x2e8: K.fn(c, 'item.GetItemTemplate', 0, ret=tpl),
                             0x2d0: K.fn(c, 'item.SetState', 2), 0x2f0: K.fn(c, 'item.SetItemOwner', 3),
                             0x210: K.fn(c, 'item.210', 1),
                             0x2c4: K.fn(c, 'item.GetItemRootTM', 2, body=lambda ee, a: (
                                 K.wfloats(ee, a[0], [r.uniform(-1, 1) for _ in range(9)]),
                                 K.wfloats(ee, a[1], ipos)))}, 'item')
        return it
    owner = [0]
    hp = [r.uniform(-1000, 1000) for _ in range(3)]
    ipos = [hp[0] + r.choice([10.0, 100.0, 149.0, 151.0, 400.0]), hp[1] + r.uniform(-500, 500), hp[2]]
    names = ['FirstAid_Large', 'FirstAid_Small', 'FirstAid_Larg', 'FirstAid_LargeX', None, 'Rifle']
    hand_item = item_obj(r.choice(names)) if r.random() < 0.6 else 0
    other_item = item_obj(r.choice(names))
    best_item = item_obj('Rifle') if r.random() < 0.8 else 0
    found_item = item_obj('FirstAid_Large') if r.random() < 0.6 else 0

    actors = []
    near_last = None
    for i in range(r.choice([0, 1, 2, 3, 5])):
        x = r.random()
        if x < 0.5:
            ap = [hp[k] + r.uniform(-100, 100) for k in range(3)]
        elif x < 0.8 and actors:
            ap = list(near_last)        # same spot as the previous actor: distance tie
        else:
            ap = [hp[0] + r.uniform(-250, 250), hp[1] + r.uniform(-600, 600), hp[2] + r.uniform(-250, 250)]
        near_last = ap
        rec = K.rnd(c, 0x10)
        e.w32(rec + 4, r.choice([2, 2, 1, 0]))
        maxhp = r.randint(50, 100)
        a = K.obj(c, 0x980, {0x1e0: K.fn(c, 'actor.IsDerivedFrom', 1, ret=rb(0.2)),
                             0x438: K.fn(c, 'actor.IsDead', 0, ret=rb(0.8)),
                             0x6a8: K.fn(c, 'actor.GetMaxHitpoints', 0, ret=maxhp),
                             0x674: K.fn(c, 'actor.GetHitpoints', 0, ret=r.choice([maxhp, maxhp - 10, maxhp + 1])),
                             0x84: K.fn(c, 'actor.GetRootPoint', 1, body=lambda ee, a_, p=ap: K.wfloats(ee, a_[0], p)),
                             0x6e8: K.fn(c, 'actor.PlaySound_Enum', 3), 0x128: K.fn(c, 'actor.SendCommand', 3)}, 'actor')
        e.w32(a + 0x54, rec)
        if r.random() < 0.3:
            e.w32(a + 0x77f, 5)
        K.setbyte(c, a + 0x920, 0.6)
        actors.append(a)
    st = {'i': -1}

    def nxt(ee, a):
        cur = ee.r32(a[2])
        i = 0 if cur == 0xffffffff else cur + 1
        ee.w32(a[2], i)
        return actors[i] if i < len(actors) else 0
    lst = K.obj(c, 0x40, {0x84: K.fn(c, 'list.near', 4, ret=nxt, sizes={0: 12, 2: 4})}, 'list')

    # ---- engine object, database, globals
    refs = {}

    def ref_of(p):
        if p not in refs:
            refs[p] = 0x100 + 8 * len(refs)
        return refs[p]
    contact = K.rnd(c, 0x10)
    e.w32(contact + 4, e.cstr(r.choice(['WaterWalk_1', 'waterswim', 'Ground', 'WaterSwimDeep'])) if r.random() < 0.9 else 0)
    ao = K.obj(c, 0x40, {0x90: K.fn(c, 'ao.90', 1)}, 'ao')
    menu = K.obj(c, 0x40, {0x2c4: K.fn(c, 'win.GetSystem', 0, ret=lambda ee, a: winsys), 0x2fc: K.fn(c, 'win.PushWindow', 1)}, 'menu')
    winsys = K.obj(c, 0x40, {0x2fc: K.fn(c, 'winsys.PushWindow', 1)}, 'winsys')
    mp = 1 if r.random() < 0.2 else 0
    cfg = K.obj(c, 0x100, {0x90: K.fn(c, 'cfg.get', 2, body=lambda ee, a: ee.w8(a[1], mp), sizes={1: 1})}, 'cfg')
    menus = K.obj(c, 0x100, {0x88: K.fn(c, 'menus.get', 2, body=lambda ee, a: ee.w32(a[1], ref_of(menu) if r.random() < 0.8 else 0), sizes={1: 4})}, 'menus')
    by_ref = {}
    tbl = {'contact': contact, 'other': other_item, 'menu': menu, 'actor0': actors[0] if actors else 0}
    for k, p in tbl.items():
        if p:
            by_ref[ref_of(p)] = p

    def r2p(ee, a):
        return by_ref.get(a[0], 0)

    def p2r(ee, a):
        return ref_of(a[0]) if a[0] else 0
    db = K.obj(c, 0x200, {0x58: K.fn(c, 'db.GeomRefToPtr', 1, ret=r2p), 0x4c: K.fn(c, 'db.PtrToRef', 1, ret=p2r),
                          0x114: K.fn(c, 'db.RegisterZMsg', 4, ret=lambda ee, a: 0xabcd0000 | (a[3] & 0xffff)),
                          0x134: K.fn(c, 'db.config', 0, ret=cfg), 0x138: K.fn(c, 'db.menus', 0, ret=menus)}, 'db')
    so = K.obj(c, 0x200, {0x1c0: K.fn(c, 'sys.TimeStampCounter', 2, st0=r.choice([0.5, 0.95, 0.9]))}, 'sys')
    e.w32(so + 0x40, now)
    e.w32(so + 0x9b, db)
    e.w32(0x70039c, so)
    lc = K.rnd(c, 0x1050)
    e.w32(lc + 0x1044, r.choice([3, 2]))
    gl = K.rnd(c, 0x2c20)
    e.w32(gl + 0x2c15, lc)
    e.w32(0x7003b8, gl)

    # ---- hooks for lifted callees that need much state
    rec_dist = r.choice([50.0, 199.0, 201.0, 500.0, 799.0, 900.0])
    rec_h = ref_of(actors[0]) if actors and r.random() < 0.8 else (0 if r.random() < 0.5 else 0x77)

    def fnr(ee, a):
        ee.wf32(a[0], rec_dist)
        return rec_h
    K.hooks(c, {0x595800: ('UpdateFollowers', 0), 0x593cc0: ('PerformDie', 0), 0x482370: ('ZPlayer::ClassFrameUpdate', 0),
                0x4cc850: ('striwcmp', 0, _wild, lambda ee, a: ee.calllog.append(('striwcmp.edx', ee.reg('edx')))),
                0x595440: ('StashItem', 2), 0x591e50: ('GetItem', 1, best_item), 0x58ff30: ('ControlSpecialItems', 0, rb(0.5)),
                0x590240: ('ControlWeapons', 0), 0x5d2e60: ('UpdateFocusSystem', 0), 0x597720: ('FindNextRecruit', 1, fnr),
                0x591d80: ('findFirstAidLarge', 0, found_item), 0x467410: ('ZTARGET::Remove', 6),
                0x592410: ('HealWounded', 1), 0x591190: ('DisplayUseAction', 0), 0x596680: ('recruitTimeout', 0),
                0x595250: ('StartRagdoll', 0), 0x5cdb70: ('ZCamHelper::ControlBody', 0), 0x59c420: ('PushEndScene', 0)})

    # ---- the hero
    dead = rb(0.7)
    rhand = K.obj(c, 0x40, {0x8: K.fn(c, 'rhand.8', 2)}, 'rhand')
    bm = K.rnd(c, 0x270)
    self = K.obj(c, 0xa00, {
        0x24c: K.fn(c, 'GetBoneModifier', 0, ret=bm), 0x438: K.fn(c, 'IsDead', 0, ret=dead),
        0x5ec: K.fn(c, 'UpdatePoolGeoms', 0), 0x428: K.fn(c, 'GetContactGeom', 0, ret=ref_of(contact) if r.random() < 0.8 else 5),
        0x504: K.fn(c, 'GetRHandItem', 0, ret=hand_item), 0x3dc: K.fn(c, 'RemoveCurrentLnkAction', 0),
        0x480: K.fn(c, 'ControlUseOneAlone', 1), 0x3a8: K.fn(c, 'NeckBoneIndex', 0, ret=r.randint(0, 30)),
        0x390: K.fn(c, 'GetIKBoneMatPos', 3), 0x98: K.fn(c, 'GetRootMatPos', 2), 0x80: K.fn(c, 'GetRootTM', 2),
        0x3f0: K.fn(c, 'CurrentLnkActionId', 0, ret=0 if r.random() < 0.6 else r.getrandbits(32)), 0x650: K.fn(c, 'GetNearestActionObject', 0, ret=ao if r.random() < 0.6 else 0),
        0x66c: K.fn(c, 'UpdateDefaultAction', 1), 0x410: K.fn(c, 'UpdateTargets', 0),
        0x84: K.fn(c, 'GetRootPoint', 1, body=lambda ee, a: K.wfloats(ee, a[0], hp)),
        0x4a8: K.fn(c, 'UpdateAimTarget', 0), 0x130: K.fn(c, 'SendCommand130', 3), 0x12c: K.fn(c, 'SendCommand12c', 3),
        0x4f8: K.fn(c, 'GetRHand', 0, ret=rhand), 0x348: K.fn(c, 'UpdateAnimationsAndGroundLink', 0),
        0x384: K.fn(c, 'GetRootCenter', 2, body=lambda ee, a: (K.wfloats(ee, a[0], [r.uniform(-1, 1) for _ in range(9)]),
                                                                K.wfloats(ee, a[1], hp))),
        0x5f0: K.fn(c, 'SetGroupPos', 2, sizes={0: 36, 1: 12})}, 'hero')
    owner[0] = self if r.random() < 0.6 else 0
    cam = K.rnd(c, 0xf00)
    K.setbyte(c, cam + 0xb45, 0.5)
    e.w32(self + 0x85a, cam if r.random() < 0.9 else 0)
    if not e.r32(self + 0x85a):
        e.w32(self + 0x85a, cam)    # +0x85a is read unconditionally at the start
        if r.random() < 0.5:
            pass
    osd = K.rnd(c, 0x2000)
    cnt = K.rnd(c, 0x900)
    e.w32(osd + 0x1d0f, cnt)
    e.w32(osd + 0x1fae, r.randint(0, 5))
    e.w32(osd + 0x1fba, r.randint(0, 5))
    e.w32(self + 0x852, osd)
    K.setbyte(c, self + 0x827, 0.8)
    fl = r.getrandbits(32)
    e.w32(self + 0x417, fl & ~(0x10000000 if r.random() < 0.7 else 0) & ~(0x40000 if r.random() < 0.5 else 0))
    e.wf32(self + 0x9f6, (now - r.choice([0, 50, 102, 103, 200, 5000])) / 1024.0)
    e.w32(self + 0x836, r.choice([0, 0, 1, 0x80, 0x81, 2]))
    e.w32(self + 0x832, r.choice([0, 0, r.getrandbits(32)]))
    e.w32(self + 0x83a, r.choice([ref_of(other_item), 0, 0x55]))
    K.setbyte(c, self + 0x70, 0.5)
    e.w32(self + 0x83e, r.choice([ref_of(other_item), 0, 0x55]))
    e.wf32(self + 0x9db, r.choice([1e38, 100.0, 10.0]))
    e.w32(self + 0x9d3, r.choice([7, 0xf, 6, 0]))
    K.setbyte(c, self + 0xeed, 0.4)
    e.w32(self + 0x9e8, lst if r.random() < 0.85 else 0)
    trec = K.rnd(c, 0x10)
    e.w32(trec + 4, r.choice([0, 1, 5, 31, 33]))
    e.w32(self + 0x54, trec)
    K.setbyte(c, self + 0x66c, 0.3)
    K.setbyte(c, self + 0x9f4, 0.5)
    e.w32(self + 0x93a, (now - r.choice([0, 0x66, 0x67, 500])) & 0xffffffff)
    e.w32(self + 0x93e, r.randint(0, 9))
    for i in range(30):
        e.wf32(self + 0x8c2 + 4 * i, r.uniform(-1000, 1000))
    t = r.choice([0.0, (now - 3000) / 1024.0, (now - 100) / 1024.0, float('nan')])
    e.wf32(self + 0x817, t)
    e.wf32(self + 0x81b, r.choice([1.0, 2.0, 5.0]))
    for i in range(3):
        e.wf32(self + 0x48 + 4 * i, r.uniform(-50, 50))
    for i in range(9):
        e.wf32(self + 0x24 + 4 * i, r.uniform(-1, 1))
    return [self]


S(0x58d000, 'ZFFHERO::ClassFrameUpdate', 'thiscall', None, ret=None, gen=_root,
  note='batch408; heavy callees hooked, small math callees as exe code')
