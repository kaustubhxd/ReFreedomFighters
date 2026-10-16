"""specs_s222.py - ladder thread batch 222: ZIKLNKOBJ small members."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, u32, F
import ladder_kit as K


def _self(c, extra=None):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    slots = {o: (n, (lambda e2, a, o=o: ((o * 0x10001 + sum(x if isinstance(x, int) else 7 for x in a)) & 0xffffffff, None, None)))
             for o, n in ((0x2b4, 1), (0x360, 0), (0x364, 0), (0x3c8, 5), (0x2a8, 2))}
    e.w32(s, K.vt(c, 'self', slots, nslots=0x100))
    ik = K.rnd(c, 0x10)
    e.w32(ik, K.vt(c, 'ik', {0x10: (4, lambda e2, a: (r.getrandbits(32), None, None)),
                            0x3c: (3, lambda e2, a: (r.getrandbits(32), None, None))}, nslots=0x20))
    e.w32(s + 0x6c, ik)

    def hk(addr, name):
        def h(e2, res):
            e2.calllog.append((name, e2.reg('ecx')))
            e2.ret(eax=0x9999)
        e.hook(addr, h)
    hk(0x4639f0, 'ZLNKOBJ::PushState')
    hk(0x463940, 'ZLNKOBJ::PopState')
    return s


def g(n, gen=None):
    return lambda c: [_self(c)] + ([c.rng.getrandbits(32) for _ in range(n)] if gen is None else gen(c))


S(0x4690b0, 'empty (ResetTargets etc.)', 'thiscall', None, ret=None, gen=g(0), note='batch222')
S(0x420060, 'ZIKLNKOBJ::CreateLnkAction (returns 0)', 'thiscall', None, ret='eax', gen=g(1), note='batch222')
for a, nm in ((0x466610, 'EnableFacing'), (0x466620, 'EnableIK'), (0x466470, 'DisableIK'), (0x466420, 'DisableFacing')):
    S(a, 'ZIKLNKOBJ::' + nm, 'thiscall', None, ret=None, gen=g(0), note='batch222')
for a, nm in ((0x466f40, 'HeadBoneIndex'), (0x466f50, 'NeckBoneIndex'), (0x466d70, 'PelvisBoneIndex'),
              (0x4673f0, 'LHandBoneIndex'), (0x466d80, 'RHandBoneIndex'), (0x467400, 'LToeBoneIndex'),
              (0x4673d0, 'PushState'), (0x467390, 'PopState')):
    S(a, 'ZIKLNKOBJ::' + nm, 'thiscall', None, ret='eax', gen=g(0), note='batch222')


def _cb(c):
    r = c.rng
    if r.random() < 0.5:
        return [0x465708] + [0 if r.random() < 0.8 else r.getrandbits(32) for _ in range(3)]
    return [r.choice([0, 0x465708 ^ 1, r.getrandbits(32)]), 0, 0, 0]


S(0x466c30, 'callback-to-id (map: RToeBoneIndex)', 'thiscall', None, ret='eax', gen=g(4, _cb), note='batch222')
S(0x465870, 'ZIKLNKOBJ::BoneAnimIdToCallBack', 'thiscall', None, ret='eax',
  gen=g(1, lambda c: [c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])]), note='batch222')
S(0x466480, 'ZIKLNKOBJ::DisplayGround', 'thiscall', None, ret='eax', gen=g(1), note='batch222')
S(0x466c10, 'ZIKLNKOBJ::HitRagdoll', 'thiscall', None, ret='eax',
  gen=g(3, lambda c: [c.rng.getrandbits(32), c.rng.getrandbits(32), F(c.fv())]), note='batch222')
S(0x466890, 'ZIKLNKOBJ::GetIKBonePos', 'thiscall', None, ret='eax', gen=g(2), note='batch222')
S(0x466830, 'ZIKLNKOBJ::GetIKBoneMat', 'thiscall', None, ret='eax', gen=g(2), note='batch222')
S(0x466870, 'ZIKLNKOBJ::GetIKBoneMatPos', 'thiscall', None, ret='eax', gen=g(3), note='batch222')
